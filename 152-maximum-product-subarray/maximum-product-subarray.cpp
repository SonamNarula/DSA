class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // Maximum product ending at current index
        int mx = nums[0];

        // Minimum product ending at current index
        int mn = nums[0];

        // Overall maximum answer
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // Negative number:
            // maximum becomes minimum and minimum becomes maximum
            if (nums[i] < 0) {
                swap(mx, mn);
            }

            // Either:
            // 1. Start a new subarray from nums[i]
            // 2. Extend previous maximum product
            mx = max(nums[i], mx * nums[i]);

            // Same logic for minimum
            mn = min(nums[i], mn * nums[i]);

            // Update global answer
            ans = max(ans, mx);
        }

        return ans;
    }
};