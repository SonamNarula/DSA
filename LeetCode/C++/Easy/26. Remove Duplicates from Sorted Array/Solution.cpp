class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Store the size of the array
        int n = nums.size();

        // Handle empty array
        if(n == 0){
            return 0;
        }

        // i points to the last unique element
        // j checks the next element
        int i = 0;
        int j = 1;

        // Traverse the array
        while(j < n){

            // Check if current element is equal to previous unique element
            if(nums[i] == nums[j]){

                // Duplicate found, remove the element at index j
                nums.erase(nums.begin() + j);

                // Array size decreases by 1
                n--;

                // Don't increment j because the next element
                // has shifted into the current index
            }

            else{

                // Found a new unique element
                // Move i to the new unique element
                i = j;

                j++;
            }
        }

        // Number of unique elements = last unique index + 1
        return i + 1;
    }
};