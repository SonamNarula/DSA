## 01. Binary Search

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1)

### Problem Description

**Task:** Given a sorted array arr[] of distinct integers and an integer k, return the 0-based index of k if it is present in the array. Otherwise, return -1.Examples:Input: arr[] = [1, 2, 3, 4, 6], k = 6

#### Examples

##### Example 1

- **Output:**
```text
-1
```
- **Explanation:** 3 is not present in the array.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-16 09:17:06
- **Status:** Correct
- **Marks:** 1

```cpp
class Solution {
  public:
    int binarySearch(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == k) return mid;
            
            else if(arr[mid] < k){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
```

*Generated on: 16/11/2026, 09:22:01*