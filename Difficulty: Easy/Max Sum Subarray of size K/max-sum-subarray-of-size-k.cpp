class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = k-1;
        
        int windowSum = 0;
        int maxSum = INT_MIN;
        
        // window sum
        for(int i = 0; i < k; i++)
        {
            windowSum += arr[i];
            
        }
        
        while(high < n){
            maxSum = max(maxSum, windowSum);
            low++;
            high++;
            windowSum += arr[high] - arr[low-1]; 
        }
        return maxSum;
        
    }
};