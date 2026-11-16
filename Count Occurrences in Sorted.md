## 01. Count Occurrences in Sorted

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1)

### Problem Description

**Task:** Given a sorted array arr[] and a number target, find the number of occurrences of target in given array. Examples:Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2

#### Examples

##### Example 1

- **Output:**
```text
3
```
- **Explanation:** target = 12 occurs 3 times in the given array so the output is 3.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-16 14:00:45
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:

    int firstOccurence(vector<int>& arr, int target) {
        int n = arr.size();

        int start = 0;
        int end = n - 1;
        int res = -1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                res = mid;
                end = mid - 1;
            }
            else if (arr[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return res;
    }

    int lastOccurence(vector<int>& arr, int target) {
        int n = arr.size();

        int start = 0;
        int end = n - 1;
        int res = -1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                res = mid;
                start = mid + 1;
            }
            else if (arr[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return res;
    }

    int countFreq(vector<int>& arr, int target) {

        int first = firstOccurence(arr, target);

        if (first == -1) return 0;

        int last = lastOccurence(arr, target);

        return last - first + 1;
    }
};
```

*Generated on: 16/11/2026, 14:01:39*