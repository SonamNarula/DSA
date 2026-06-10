class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int WindowSum = 0;
        int n = arr.size();
        
        // first window
        for (int i = 0; i < k; i++){
            WindowSum+=arr[i];
        }
        int maxSum = WindowSum;
        
        // slide the window
        for(int right = k; right<n;right++){
            int left = right - k;
            
            WindowSum += arr[right];
            WindowSum -= arr[left];
            
            maxSum = max(maxSum,WindowSum);
        }
        return maxSum;
    }
};
