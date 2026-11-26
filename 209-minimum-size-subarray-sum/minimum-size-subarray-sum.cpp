class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for (int high = 0; high < n; high++) {
            
            // Add current element to the window
            sum += nums[high];

            // Shrink the window while sum is >= target
            while (sum >= target) {
                
                // Current window length
                int len = high - low + 1;

                // Update minimum length
                minLen = min(minLen, len);

                // Remove leftmost element
                sum -= nums[low];

                // Move left pointer
                low++;
            }
        }

        // If no valid subarray exists
        if (minLen == INT_MAX)
            return 0;

        return minLen;
    }
};