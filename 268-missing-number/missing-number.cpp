class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // Start with n because expected range is 0 to n
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++) {

            // XOR with expected number
            ans ^= i;

            // XOR with actual array number
            ans ^= nums[i];
        }

        // Same numbers cancel, missing number remains
        return ans;
    }
};