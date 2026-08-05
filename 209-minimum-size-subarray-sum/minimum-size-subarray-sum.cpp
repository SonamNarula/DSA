class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        // Two pointers representing the sliding window
        int low = 0;
        int high = 0;

        // Stores the minimum length of a valid subarray
        int result = INT_MAX;

        // Stores the sum of the current window
        int sum = 0;

        // Expand the window by moving the right pointer
        while (high < n) {

            // Include the current element in the window
            sum += nums[high];

            // If the current window satisfies the condition,
            // try shrinking it from the left to find
            // the minimum possible valid window.
            while (sum >= target) {

                // Current window length
                int len = high - low + 1;

                // Update the minimum length
                result = min(result, len);

                // Remove the leftmost element
                // and shrink the window
                sum -= nums[low];
                low++;
            }

            // Expand the window further
            high++;
        }

        // If result was never updated,
        // no valid subarray exists.
        if (result == INT_MAX) {
            return 0;
        }

        return result;
    }
};