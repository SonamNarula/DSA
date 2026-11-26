#include <iostream>
#include <vector>
 
using namespace std;
 
int parent[200005];
 
int find_set(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent[i]);
}
 
void union_sets(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}
 
void solve() {
    int n, x, y;
    if (!(cin >> n >> x >> y)) return;
    
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 1; i + x <= n; i++) {
        union_sets(i, i + x);
    }
    
    for (int i = 1; i + y <= n; i++) {
        union_sets(i, i + y);
    }
    
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (find_set(i) != find_set(p[i])) {
            ok = false;
            break;
        }
    }
    
    if (ok) {
        cout << "YES
";
    } else {
        cout << "NO
";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}