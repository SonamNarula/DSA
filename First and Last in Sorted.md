## 01. First and Last in Sorted

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1)

### Problem Description

**Task:** Given a sorted array arr[] with possibly some duplicates, find the first and last occurrences of an element x in the given array.Note: If the number x is not found in the array then return both the indices as -1.Examples:Input: arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5

#### Examples

##### Example 1

- **Output:**
```text
[2, 5]
```
- **Explanation:** First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5

##### Example 2

- **Input:**
```text
arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125], x = 7
```
- **Output:**
```text
[-1, -1]
```
- **Explanation:** No occurrence of 4 in the array, so, output is [-1, -1]

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-16 13:25:17
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
  
   int firstOccurrence(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int res = -1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                res = mid;
                end = mid - 1;  // Search left
            }
            else if (nums[mid] < target) {
                start = mid + 1; // Search right
            }
            else {
                end = mid - 1;   // Search left
            }
        }

        return res;
    }

    // Find last occurrence
    int lastOccurrence(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int res = -1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                res = mid;
                start = mid + 1; // Search right
            }
            else if (nums[mid] < target) {
                start = mid + 1; // Search right
            }
            else {
                end = mid - 1;   // Search left
            }
        }

        return res;
    }
    vector<int> find(vector<int>& nums, int target) {
        // code here
          int first = firstOccurrence(nums, target);
        int last = lastOccurrence(nums, target);

        return {first, last};
        
    }
};
```

*Generated on: 16/11/2026, 13:25:30*