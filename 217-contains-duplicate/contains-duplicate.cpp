class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Store elements we have already visited
        unordered_set<int> seen;
        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            // If the element is already present, it's a duplicate
            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }
            // Otherwise, store the element in the set
            seen.insert(nums[i]);
        }
        // No duplicates found
        return false;
    }
};