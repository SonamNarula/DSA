#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<int>> dp(4, vector<int>(MAXX, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            auto ndp = dp;

            for (int cnt = 0; cnt < 3; cnt++) {
                for (int val = 0; val < MAXX; val++) {
                    if (dp[cnt][val]) {
                        ndp[cnt + 1][val ^ x] = 1;
                    }
                }
            }

            dp.swap(ndp);
        }

        vector<int> vis(MAXX, 0);

        // Triplets with repeated indices -> original values only
        for (int x : nums)
            vis[x] = 1;

        // Triplets with 3 distinct indices
        for (int val = 0; val < MAXX; val++)
            if (dp[3][val])
                vis[val] = 1;

        return accumulate(vis.begin(), vis.end(), 0);
    }
};