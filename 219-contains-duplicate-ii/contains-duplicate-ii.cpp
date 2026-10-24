class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> seen;

        for (int i = 0; i < n; i++) {

            // If the current element already exists in the set,
            // it means we found a duplicate within distance k.
            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }

            // Store the current element.
            seen.insert(nums[i]);

            // Keep only the last k elements in the set.
            if (seen.size() > k) {
                seen.erase(nums[i - k]);
            }
        }

        return false;
    }
};