class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Prefix sum 0 already exists once
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Current prefix sum
            sum += nums[i];

            // We need a previous sum = sum - k
            if (mp.count(sum - k)) {
                count += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};