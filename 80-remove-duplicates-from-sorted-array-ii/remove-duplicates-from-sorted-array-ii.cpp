class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // k = position where the next valid element
        // will be placed
        int k = 0;

        // i scans every element of the array
        for(int i = 0; i < nums.size(); i++) {

            // First 2 elements are always allowed
            // because each element can appear at most twice
            if(k < 2) {

                nums[k] = nums[i];
                k++;
            }

            // For elements after the first two,
            // compare current element with the element
            // 2 positions behind in the valid portion
            else if(nums[i] != nums[k - 2]) {

                // Current element is allowed,
                // so place it at position k
                nums[k] = nums[i];

                // Move k to the next empty position
                k++;
            }

            // If nums[i] == nums[k - 2],
            // adding it would make the same element
            // appear 3 times, so we simply skip it
        }

        // k represents the number of valid elements
        return k;
    }
};