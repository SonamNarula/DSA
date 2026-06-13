#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int target;
            cin >> target;
            ans[target].push_back(i);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i].size();
        for (int x : ans[i]) {
            cout << " " << x;
        }
        cout << "\n";
    }
    
    return 0;
}
