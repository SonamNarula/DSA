class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suf(n + 1, 0);
        for (int i = n - 1; i >= 0; --i)
            suf[i] = suf[i + 1] + piles[i];

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int m = n; m >= 1; --m) {
                if (i + 2 * m >= n) {
                    dp[i][m] = suf[i];
                    continue;
                }

                for (int x = 1; x <= 2 * m; ++x) {
                    dp[i][m] = max(
                        dp[i][m],
                        suf[i] - dp[i + x][max(m, x)]
                    );
                }
            }
        }

        return dp[0][1];
    }
};