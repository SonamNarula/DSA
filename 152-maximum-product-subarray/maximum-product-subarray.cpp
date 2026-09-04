class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // Maximum product of a subarray ending at current index
        int bestEnding = nums[0];

        // Minimum product is also important because:
        // negative × negative = positive
        int worstEnding = nums[0];

        // Maximum product found so far
        int ans = nums[0];

        for (int i = 1; i < n; i++) {

            // Option 1: Extend the previous maximum product
            int v1 = bestEnding * nums[i];

            // Option 2: Extend the previous minimum product
            // This can become maximum if nums[i] is negative
            int v2 = worstEnding * nums[i];

            // Option 3: Start a new subarray from nums[i]
            int v3 = nums[i];

            // Best product ending at current index
            int newBest = max(v1, max(v2, v3));

            // Worst product ending at current index
            // We need this for future negative numbers
            int newWorst = min(v1, min(v2, v3));

            // Update both AFTER calculating them
            bestEnding = newBest;
            worstEnding = newWorst;

            // Keep track of the best product seen anywhere
            ans = max(ans, bestEnding);
        }

        return ans;
    }
};