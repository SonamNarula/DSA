class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;

        for(int j = 1; j < nums.size(); j++) {

            // Found a new unique element
            if(nums[j] != nums[i]) {

                // Move to next position
                i++;

                // Place the unique element there
                nums[i] = nums[j];
            }
        }

        // Number of unique elements
        return i + 1;
    }
};