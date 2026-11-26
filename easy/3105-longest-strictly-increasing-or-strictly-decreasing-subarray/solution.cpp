class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasing = 1, decreasing = 1;
        int maxIncreasing = 1, maxDecreasing = 1;
        int size = nums.size();
        for(int i = 1 ; i < size ; ++i){
            if(nums[i]>nums[i-1]){
                increasing++;
                maxIncreasing = max(maxIncreasing,increasing);
                decreasing = 1 ; 
            }
            else if(nums[i]<nums[i-1]){
                decreasing++;
                maxDecreasing = max(maxDecreasing, decreasing);
                increasing = 1 ; 
            }
            else{
                increasing = 1 ; 
                decreasing = 1 ;
            }
        }

        cout<<maxIncreasing<<endl;
        cout<<maxDecreasing<<endl;

        // 50,32,13,18,32,16,12,4,18,36,5,6,12,14,37,45,36,13,14,48,8,45,33,39,40,8,45,4,36,13,44,32,15,35,1,50,14,41,43,17,13,11,44,3,25,14,10,7,2,44

        return max(maxIncreasing, maxDecreasing);
    }
};