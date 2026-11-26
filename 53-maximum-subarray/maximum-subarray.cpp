class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Best subarray ending at index 0
        int curr = nums[0];

        // Best answer anywhere
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // Start fresh OR extend previous subarray
            curr = max(nums[i], curr + nums[i]);

            // Update global maximum
            ans = max(ans, curr);
        }

        return ans;
    }
};