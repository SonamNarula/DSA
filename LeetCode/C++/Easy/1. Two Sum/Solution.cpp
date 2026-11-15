class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Total number of elements in the array
        int n = nums.size();

        // Hash Map: stores {number, index}
        unordered_map<int, int> mp;

        // Traverse the array
        for(int i = 0; i < n; i++){

            // Calculate the number needed to reach the target
            int complement = target - nums[i];

            // Check if complement already exists in the map
            if(mp.count(complement)){

                // If found, return the index of complement and current index
                return {mp[complement], i};
            }

            // Store current number along with its index
            mp[nums[i]] = i;
        }

        // If no valid pair is found, return an empty vector
        return {};
    }
};