class Solution{
    public:
    int majorityElement(vector<int>& arr){
        int n = arr.size();
        
        int count = 0;
        int candidate = 0;

        for(int i = 0; i < n; i++){
            // no active candidate
            if(count==0){
                candidate = arr[i];
            }
            // element supports the candidate
            if(nums[i] == candidate){
                count++;
            }
            //different element cancels 1 vote
            else{
                count--;
            }
        }
        return candidate;
    }
};