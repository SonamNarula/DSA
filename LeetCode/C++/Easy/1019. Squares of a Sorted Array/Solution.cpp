class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();

        // finding first non negative element
        int mid = 0;
        while(mid < n && nums[mid] < 0){
            mid++;
        }

        // 2 sorted arrays of squares
        vector<int>negative;
        vector<int>positive;

        // traversing negative subarray in backward form
        for(int i = mid-1;i>=0;i--){
            negative.push_back(nums[i]  * nums[i]);
        }

         // traversing positive subarray
        for(int i = mid;i<n;i++){
            positive.push_back(nums[i]  * nums[i]);
        }

        // merge both sorted array in ans
        vector<int>ans;
        int i = 0; //ptr of negative array
        int j = 0; //ptr of positive array

        while(i<negative.size() && j<positive.size())
        {
            if(negative[i] < positive[j]){
                ans.push_back(negative[i]);
                i++;
            }

            else{
                ans.push_back(positive[j]);
                j++;
            }
        }

        // add remaining elements from -ve 
        while(i<negative.size()){
            ans.push_back(negative[i]);
            i++;
        }
        // add remaining elements from +ve 
        while(j<positive.size()){
            ans.push_back(positive[j]);
            j++;
        }

        return ans;
    }
};