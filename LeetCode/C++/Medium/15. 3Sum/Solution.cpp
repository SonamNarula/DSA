class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        // Step 1: Array sort karo
        sort(nums.begin(), nums.end());

        // Step 2: Ek element fixed rakho
        for (int i = 0; i < n - 2; i++) {

            // Duplicate fixed elements skip karo
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Step 3: Two pointers initialize karo
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Valid triplet mila
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Dono pointers move karo
                    left++;
                    right--;

                    // Duplicate left values skip karo
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Duplicate right values skip karo
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < 0) {
                    // Sum chhota hai; increase karna hai
                    left++;
                } else {
                    // Sum bada hai; decrease karna hai
                    right--;
                }
            }
        }

        return result;
    }
};