class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0;
        int end = n-1;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;

            }
            else if(target > nums[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return start;
        // low instead of -1, bcoz when the loop ends, low is exactly the insertion position
    }
};