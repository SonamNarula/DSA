class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            // Calculate the number required to reach target.
            int complement = target - nums[i];

            // Check whether required number was seen earlier.
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // Store current number with its index.
            mp[nums[i]] = i;
        }

        return {};
    }
};