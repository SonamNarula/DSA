#include <vector>
#include <algorithm>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // Step 1: Precompute suffix minimums
        std::vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = std::min(nums[i], suffMin[i + 1]);
        }

        // Step 2: Compute running prefix maximums and check condition
        int prefMax = nums[0];
        for (int i = 0; i < n; ++i) {
            prefMax = std::max(prefMax, nums[i]);
            
            // Check instability score
            if (prefMax - suffMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};