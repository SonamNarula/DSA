class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int left = 0;

        for (int right = 0; right < arr.size(); right++) {

            if (arr[right] != 0) {
                swap(arr[left], arr[right]);
                left++;
            }
        }
        
    }
};



// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {

        
//     }
// };