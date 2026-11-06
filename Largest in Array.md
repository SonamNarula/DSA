## 01. Largest in Array

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1)

### Problem Description

**Task:** Given an array arr[]. The task is to find the largest element and return it.Examples:Input: arr[] = [1, 8, 7, 56, 90]

#### Examples

##### Example 1

- **Output:**
```text
10
```
- **Explanation:** There is only one element which is the largest.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-06 08:04:10
- **Status:** Correct
- **Marks:** 1

```cpp
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here

        int n = arr.size();
        int maxi = INT_MIN;

        for(int i = 0;i < n; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
            }
        }
        return maxi;


    }
};
```

*Generated on: 11/6/2026, 8:04:22 AM*