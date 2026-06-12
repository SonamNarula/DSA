#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DFS to compute depths, parent table, and up[u][b] (closest ancestor with bit b set)
void dfs(int u, int p, const vector<int>& a, const vector<vector<int>>& adj, 
         vector<int>& depth, vector<vector<int>>& parent, vector<vector<int>>& up) {
         
    parent[u][0] = p;
    for (int i = 1; i < 18; i++) {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }
    
    for (int b = 0; b < 20; b++) {
        if ((a[u] >> b) & 1) {
            up[u][b] = u;
        } else {
            up[u][b] = (u == 1 ? 0 : up[p][b]);
        }
    }
    
    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u, a, adj, depth, parent, up);
        }
    }
}

// Computes Lowest Common Ancestor (LCA) using binary lifting
int get_lca(int u, int v, const vector<int>& depth, const vector<vector<int>>& parent) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int i = 17; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 17; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> depth(n + 1, 0);
    vector<vector<int>> parent(n + 1, vector<int>(18, 0));
    vector<vector<int>> up(n + 1, vector<int>(20, 0));
    
    depth[1] = 1;
    dfs(1, 0, a, adj, depth, parent, up);
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        
        int lca = get_lca(x, y, depth, parent);
        
        // Collect left non-zero nodes from x up to LCA (excluding LCA)
        vector<int> left_nodes;
        int curr = x;
        while (true) {
            int next_node = 0;
            for (int b = 0; b < 20; b++) {
                int node = up[curr][b];
                if (node != 0 && depth[node] > depth[lca]) {
                    if (next_node == 0 || depth[node] > depth[next_node]) {
                        next_node = node;
                    }
                }
            }
            if (next_node == 0) break;
            left_nodes.push_back(next_node);
            curr = parent[next_node][0];
        }
        
        // Collect right non-zero nodes from y up to LCA (excluding LCA)
        vector<int> right_nodes;
        curr = y;
        while (true) {
            int next_node = 0;
            for (int b = 0; b < 20; b++) {
                int node = up[curr][b];
                if (node != 0 && depth[node] > depth[lca]) {
                    if (next_node == 0 || depth[node] > depth[next_node]) {
                        next_node = node;
                    }
                }
            }
            if (next_node == 0) break;
            right_nodes.push_back(next_node);
            curr = parent[next_node][0];
        }
        
        // Merge nodes in order of their occurrence on the path x -> y
        int k = depth[x] + depth[y] - 2 * depth[lca] + 1;
        vector<pair<int, int>> w; // Stores pairs of {path_index, value}
        
        for (int node : left_nodes) {
            int pos = depth[x] - depth[node] + 1;
            w.push_back({pos, a[node]});
        }
        if (a[lca] > 0) {
            int pos = depth[x] - depth[lca] + 1;
            w.push_back({pos, a[lca]});
        }
        reverse(right_nodes.begin(), right_nodes.end());
        for (int node : right_nodes) {
            int pos = depth[x] - 2 * depth[lca] + depth[node] + 1;
            w.push_back({pos, a[node]});
        }
        
        int p = w.size();
        if (p == 0) {
            // Path contains only zeros, so all subsegments are valid
            long long ans = (long long)k * (k + 1) / 2;
            cout << ans << "\n";
            continue;
        }
        
        // Compute the next occurrence of shared bits
        vector<int> first_occ(20, k + 1);
        vector<int> next_pos(p, k + 1);
        for (int j = p - 1; j >= 0; j--) {
            int pos = w[j].first;
            int val = w[j].second;
            
            int nxt = k + 1;
            for (int b = 0; b < 20; b++) {
                if ((val >> b) & 1) {
                    nxt = min(nxt, first_occ[b]);
                }
            }
            next_pos[j] = nxt;
            
            for (int b = 0; b < 20; b++) {
                if ((val >> b) & 1) {
                    first_occ[b] = pos;
                }
            }
        }
        
        // Compute suffix minimums of R(l)
        vector<int> R_nz(p, k + 1);
        R_nz[p - 1] = next_pos[p - 1] - 1;
        for (int j = p - 2; j >= 0; j--) {
            R_nz[j] = min(R_nz[j + 1], next_pos[j] - 1);
        }
        
        // Perform sum over all intervals
        long long total_sum_R = (long long)(k - w[p - 1].first) * k;
        for (int j = 0; j < p; j++) {
            long long len = w[j].first - (j > 0 ? w[j - 1].first : 0);
            total_sum_R += len * R_nz[j];
        }
        
        long long total_sum_L = (long long)k * (k + 1) / 2;
        long long ans = total_sum_R - total_sum_L + k;
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
