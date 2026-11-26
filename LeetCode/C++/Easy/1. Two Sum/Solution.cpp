class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Number -> its index
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            // Check if required number was seen earlier
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // Store current number and its index
            mp[nums[i]] = i;
        }

        return {};
    }
};