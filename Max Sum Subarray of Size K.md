## 01. Max Sum Subarray of Size K

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1?utm_source=chatgpt.com)

### Problem Description

**Task:** Given an array of integers arr[] and a number k. Return the maximum sum of a subarray of size k.Note: A subarray is a contiguous part of any given array.Examples:Input: arr[] = [100, 200, 300, 400], k = 2

#### Examples

##### Example 1

- **Output:**
```text
400
```
- **Explanation:** arr_3 = 400, which is maximum.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (5)

#### Solution 1 (C++)

- **Submitted:** 2026-11-06 17:58:19
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        
        

            int left = 0;
            int sum = 0;
            int ans = INT_MIN;

            for (int right = 0; right < arr.size(); right++) {

                sum += arr[right];

                // Window exceeds K
                if (right - left + 1 > k) {
                    sum -= arr[left];
                    left++;
                }

                // Process complete window
                if (right - left + 1 == k) {
                    ans = max(ans, sum);
                }
            }

            return ans;
        

    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-09-08 10:25:13
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int low = 0;
        
        long long sum = 0;
        long long ans = LLONG_MIN;
        
        for(int high = 0; high < n; high++){
            sum += arr[high];
            
            if(high - low + 1 > k){
                sum -= arr[low];
                low++;
            }
            if(high - low + 1 == k)
                ans = max(ans, sum);
        }
        return ans;
        
    }
};
```

#### Solution 3 (C++)

- **Submitted:** 2026-09-08 09:27:10
- **Status:** Correct
- **Marks:** 0

```cpp
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
```

#### Solution 4 (C++)

- **Submitted:** 2026-08-05 06:28:42
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = k-1;
        // edge cases
        if(n<k || n==0){
        return 0;}
        
        // creating a window and finding sum of first window
        int windowSum = 0;
        int maxSum = INT_MIN;
        
        for(int i = 0; i < k; i++){
            windowSum += arr[i];
        }
        
        while(high<n){
            maxSum = max(maxSum, windowSum);
            low++;
            high++;
            
            windowSum += arr[high] - arr[low-1];
        }
        return maxSum;
        
    }
};
```

#### Solution 5 (C++)

- **Submitted:** 2026-08-03 08:10:24
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {

        int n = arr.size();
        if (n < k) return 0;

        int windowSum = 0;
        int maxSum = INT_MIN;

        // First window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        maxSum = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};
```

*Generated on: 11/6/2026, 6:10:29 PM*