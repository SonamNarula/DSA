class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        int low = 0;

        long long sum = 0;

        double ans = -1e18;

        for (int high = 0; high < n; high++) {

            // Current element ko window mein add karo
            sum += nums[high];

            // Agar window size k s
            // e badi ho gayi
            // toh leftmost element remove karo
            if (high - low + 1 > k) {
                sum -= nums[low];
                low++;
            }

            // Jab window ka size exactly k ho
            if (high - low + 1 == k) {

                // Current window ka average
                double average = (double)sum / k;

                // Maximum average update karo
                ans = max(ans, average);
            }
        }

        return ans;
    }
};