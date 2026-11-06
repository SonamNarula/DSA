class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int low = 0; //position for 0
        int mid = 0; //position for current element
        int high = n-1; //position for 2


        while (mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;

            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};