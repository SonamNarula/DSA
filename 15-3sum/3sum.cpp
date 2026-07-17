class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;
            int target = -nums[i];

            while (j < k) {
                int sum = nums[j] + nums[k];

                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // skip duplicates
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result;
    }
};