class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        // remainder -> first index
        unordered_map<int, int> mp;

        mp[0] = -1;

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            int rem = sum % k;

            if (rem < 0) {
                rem += k;
            }

            // Same remainder appeared before
            if (mp.count(rem)) {

                // Check length >= 2
                if (i - mp[rem] >= 2) {
                    return true;
                }

            } else {

                // Store first occurrence only
                mp[rem] = i;
            }
        }

        return false;
    }
};