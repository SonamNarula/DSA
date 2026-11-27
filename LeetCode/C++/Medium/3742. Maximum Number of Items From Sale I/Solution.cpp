class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int sz = items.size();
        vector<int> free;
        for(int i = 0; i < sz; ++i) {
            int count = 0;
            for(int j = 0; j < sz; ++j) {
                count += (i != j && items[j][0] % items[i][0] == 0);
            }
            free.push_back(count);
        }
        vector<int> dp(budget+1, 0);
        for(int i = 0; i < sz; ++i) {
            int cost = items[i][1];
            for(int b = budget - cost; b >= 0; --b) { //0-1 knapsack with free reward
                dp[b + cost] = max(dp[b + cost], dp[b]+1+free[i]);
            }
            for(int b = 0; b <= budget - cost; ++b) { //unbounded knapsack
                dp[b + cost] = max(dp[b + cost], dp[b]+1);
            }
        }
        return dp[budget];
    }
};