// Squares of a Sorted Array | Brute Force (Square + Sort)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        // Step 1: Square all elements
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i] * nums[i];
        }

        // Step 2: Sort the array
        sort(nums.begin(), nums.end());

        return nums; 
    }
};