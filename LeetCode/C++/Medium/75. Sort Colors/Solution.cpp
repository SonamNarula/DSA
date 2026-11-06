
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        // Three pointers
        int low = 0;        // Position for the next 0
        int mid = 0;        // Current element to check
        int high = n - 1;   // Position for the next 2

        // Process elements until mid crosses high
        while (mid <= high) {

            // Case 1: Current element is 0
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);

                low++;  // Next position for 0
                mid++;  // Current element is processed
            }

            // Case 2: Current element is 1
            else if (nums[mid] == 1) {
                mid++;  // 1 is already in the correct region
            }

            // Case 3: Current element is 2
            else {
                swap(nums[mid], nums[high]);

                high--; // Next position for 2

                // Don't increment mid!
                // The swapped element from high is not checked yet.
            }
        }
    }
};
