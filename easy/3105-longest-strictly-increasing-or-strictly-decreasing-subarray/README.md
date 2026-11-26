# Longest Strictly Increasing or Strictly Decreasing Subarray

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an array of integers `nums`. Return *the length of the **longest** subarray of *`nums`* which is either **strictly increasing** or **strictly decreasing***.

 

Original
C++
**Example 1:**

**Input:** nums = [1,4,3,3,2]

**Output:** 2

**Explanation:**

The strictly increasing subarrays of `nums` are `[1]`, `[2]`, `[3]`, `[3]`, `[4]`, and `[1,4]`.

The strictly decreasing subarrays of `nums` are `[1]`, `[2]`, `[3]`, `[3]`, `[4]`, `[3,2]`, and `[4,3]`.

Hence, we return `2`.

**Example 2:**

**Input:** nums = [3,3,3,3]

**Output:** 1

**Explanation:**

The strictly increasing subarrays of `nums` are `[3]`, `[3]`, `[3]`, and `[3]`.

The strictly decreasing subarrays of `nums` are `[3]`, `[3]`, `[3]`, and `[3]`.

Hence, we return `1`.

**Example 3:**

**Input:** nums = [3,2,1]

**Output:** 3

**Explanation:**

The strictly increasing subarrays of `nums` are `[3]`, `[2]`, and `[1]`.

The strictly decreasing subarrays of `nums` are `[3]`, `[2]`, `[1]`, `[3,2]`, `[2,1]`, and `[3,2,1]`.

Hence, we return `3`.

 

**Constraints:**

- 1 <= nums.length <= 50
- 1 <= nums[i] <= 50

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 3.61%)  
**Memory:** 27.9 MB (beats 47.29%)  
**Submitted:** 2026-11-13T07:27:19.403Z  

```cpp
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasing = 1, decreasing = 1;
        int maxIncreasing = 1, maxDecreasing = 1;
        int size = nums.size();
        for(int i = 1 ; i < size ; ++i){
            if(nums[i]>nums[i-1]){
                increasing++;
                maxIncreasing = max(maxIncreasing,increasing);
                decreasing = 1 ; 
            }
            else if(nums[i]<nums[i-1]){
                decreasing++;
                maxDecreasing = max(maxDecreasing, decreasing);
                increasing = 1 ; 
            }
            else{
                increasing = 1 ; 
                decreasing = 1 ;
            }
        }

        cout<<maxIncreasing<<endl;
        cout<<maxDecreasing<<endl;

        // 50,32,13,18,32,16,12,4,18,36,5,6,12,14,37,45,36,13,14,48,8,45,33,39,40,8,45,4,36,13,44,32,15,35,1,50,14,41,43,17,13,11,44,3,25,14,10,7,2,44

        return max(maxIncreasing, maxDecreasing);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/)