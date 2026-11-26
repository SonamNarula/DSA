## 01. Sort 0s, 1s and 2s

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1)

### Problem Description

**Task:** Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order. Examples:Input: arr[] = [0, 1, 2, 0, 1, 2]

#### Examples

##### Example 1

- **Output:**
```text
[0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
```
- **Explanation:** 0s, 1s and 2s are segregated into ascending order.Follow up: Could you come up with a one-pass algorithm using only constant extra space?

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (2)

#### Solution 1 (C++)

- **Submitted:** 2026-10-30 13:45:41
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        
      int zeroes = 0;
      int ones = 0;
      int twos = n-1;
        
        while(ones <= twos){
            
            if(arr[ones] == 0)
            {
                swap(arr[ones], arr[zeroes]);
                zeroes++;
                ones++;
            }
            else if(arr[ones] == 1)
            {
                ones++;
            }
            else{
                swap(arr[ones], arr[twos]);
                twos--;
            }
        }
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-10-30 13:44:45
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        
      int zeroes = 0;
      int ones = 0;
      int twos = n-1;
        
        while(ones <= twos){
            
            if(arr[ones] == 0)
            {
                swap(arr[ones], arr[zeroes]);
                zeroes++;
                ones++;
            }
            else if(arr[ones] == 1)
            {
                ones++;
            }
            else{
                swap(arr[ones], arr[twos]);
                twos--;
            }
        }
    }
};
```

*Generated on: 10/30/2026, 1:55:48 PM*