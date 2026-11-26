
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Sum of numbers from 0 to n
        int rangeSum = n * (n + 1) / 2;

        // Subtract every array element
        for(int i = 0; i < n; i++) {
            rangeSum -= nums[i];
        }

        // Remaining value is the missing number
        return rangeSum;
    }
};
