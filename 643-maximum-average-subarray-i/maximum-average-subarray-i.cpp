class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        // Step 1: Calculate first window sum
        double windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        // Step 2: Initially first window is maximum
        double maxSum = windowSum;

        // Step 3: Start sliding from index k
        for (int right = k; right < n; right++) {


            windowSum -= nums[right - k];


            windowSum += nums[right];


            maxSum = max(maxSum, windowSum);
        }

        // Step 4: Convert maximum sum into average
        return maxSum / k;
    }
};