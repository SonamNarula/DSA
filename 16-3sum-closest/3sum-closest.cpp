class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // Step 1: Sort the array
        // Sorting allows us to use the two-pointer technique
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initially, assume the first 3 elements give us
        // the closest sum
        int closest = nums[0] + nums[1] + nums[2];

        // Step 2: Fix one element nums[i]
        // We need at least 2 elements after i,
        // hence i < n - 2
        for(int i = 0; i < n - 2; i++) {

            // Left pointer starts just after i
            int left = i + 1;

            // Right pointer starts from the last element
            int right = n - 1;

            // Keep searching while the two pointers
            // have not crossed
            while(left < right) {

                // Current 3 elements:
                // nums[i], nums[left], nums[right]
                int sum = nums[i] + nums[left] + nums[right];

                // Check whether current sum is closer
                // to target than our previous closest sum
                if(abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                // If we found exactly the target,
                // we cannot get anything closer than this
                if(sum == target) {
                    return sum;
                }

                // If sum is smaller than target,
                // we need to increase the sum.
                // Since array is sorted, move left forward.
                if(sum < target) {
                    left++;
                }

                // If sum is greater than target,
                // we need to decrease the sum.
                // Move right backward.
                else {
                    right--;
                }
            }
        }

        // After checking all possible combinations,
        // return the sum closest to target
        return closest;
    }
};