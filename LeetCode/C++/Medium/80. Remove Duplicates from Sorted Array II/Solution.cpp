class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        if(n < 2) return n;

        int k = 0; // Position for next valid element

        for(int j = 0; j < n; j++){

            // Allow first 2 elements or check if current
            // element is different from the element 2 places back.
            if(k < 2 || nums[j] != nums[k-2]){

                nums[k] = nums[j]; // Place valid element
                k++;
            }
        }

        return k; // Total number of valid elements
    }
};