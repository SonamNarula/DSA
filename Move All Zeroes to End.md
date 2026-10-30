## 01. Move All Zeroes to End

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1)

### Problem Description

**Task:** Given an array arr[] of non-negative integers, move all the zeros to the end of the array while maintaining the relative order of the non-zero elements. Perform the operation in place, without using an extra array.Examples:Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]

#### Examples

##### Example 1

- **Output:**
```text
[1, 2, 4, 3, 5, 0, 0, 0]
```
- **Explanation:** The three zeros are moved to the end while the order of the non-zero elements remains unchanged.

##### Example 2

- **Input:**
```text
arr[] = [10, 20, 30]
```
- **Output:**
```text
[10, 20, 30]
```
- **Explanation:** No change in array as there are no 0s.

##### Example 3

- **Input:**
```text
arr[] = [0, 0]
```
- **Output:**
```text
[0, 0]
```
- **Explanation:** No change in array as there are all 0s.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (3)

#### Solution 1 (C++)

- **Submitted:** 2026-10-30 14:02:49
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        
        
        int n = arr.size();
        int i = 0;
        
        for(int j = 0;j<n;j++){
            if(arr[j] != 0){
                // i++;
                swap(arr[j],arr[i]);
                i++;
            }
            
        }
        
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-07-18 05:41:03
- **Status:** Correct
- **Marks:** 0

```cpp
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
```

#### Solution 3 (C++)

- **Submitted:** 2026-07-12 12:55:42
- **Status:** Correct
- **Marks:** 2

```cpp
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
```

*Generated on: 10/30/2026, 2:03:03 PM*