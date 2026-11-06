class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Sort so we can use two pointers
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // edge case
        if (n < 3) {
            return {};
        }

        // Fix one number at a time
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Find two numbers after i whose sum is -nums[i]
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Move both pointers after finding one triplet
                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < 0) {
                    // Need a larger sum: move left forward
                    left++;
                } else {
                    // Need a smaller sum: move right backward
                    right--;
                }
            }
        }

        return ans;
    }
};