class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Step 1: Sort the array
        // Sorting helps us:
        // 1. Use two-pointer technique
        // 2. Easily skip duplicate elements
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();

        // We will fix nums[i] as the first element
        // and find two other elements whose sum is -nums[i]
        for(int i = 0; i < n; i++){

            // Skip duplicate values for the first element
            // Example: [-1, -1, 0, 1]
            // We don't want to process -1 twice
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            // We need:
            // nums[i] + nums[left] + nums[right] = 0
            //
            // Therefore:
            // nums[left] + nums[right] = -nums[i]
            int target = -nums[i];

            // Two pointers
            // left starts just after i
            // right starts at the end
            int left = i + 1;
            int right = n - 1;

            // Keep searching while two pointers don't cross
            while(left < right){

                // Current sum of the two-pointer elements
                int curr = nums[left] + nums[right];

                // We found a valid triplet
                // nums[i] + nums[left] + nums[right] = 0
                if(curr == target){

                    // Store the triplet
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Move both pointers to search for another pair
                    left++;
                    right--;

                    // Skip duplicate values on the left
                    // Example: if left points to another same value,
                    // don't create the same triplet again
                    while(left < right && nums[left] == nums[left-1])
                        left++;

                    // Skip duplicate values on the right
                    while(left < right && nums[right] == nums[right+1])
                        right--;
                }

                // Current sum is too small
                // Since array is sorted, increase left
                // to get a larger value
                else if(curr < target)
                    left++;

                // Current sum is too large
                // Since array is sorted, decrease right
                // to get a smaller value
                else
                    right--;
            }
        }

        // Return all unique triplets
        return ans;
    }
};