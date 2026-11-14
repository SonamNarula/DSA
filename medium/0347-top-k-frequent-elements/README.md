# Top K Frequent Elements

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums` and an integer `k`, return *the* `k` *most frequent elements*. You may return the answer in **any order**.

 

Original
C++
**Example 1:**

**Input:** nums = [1,1,1,2,2,3], k = 2

**Output:** [1,2]

**Example 2:**

**Input:** nums = [1], k = 1

**Output:** [1]

**Example 3:**

**Input:** nums = [1,2,1,2,1,2,3,1,3,2], k = 2

**Output:** [1,2]

 

**Constraints:**

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104
- k is in the range [1, the number of unique elements in the array].
- It is guaranteed that the answer is unique.

 

**Follow up:** Your algorithm's time complexity must be better than `O(n log n)`, where n is the array's size.

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 69.98%)  
**Memory:** 18 MB (beats 73.16%)  
**Submitted:** 2026-11-14T11:36:47.783Z  

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {


        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }


        vector<pair<int, int>> arr;

        for (auto& entry : freq) {



            arr.push_back({entry.second, entry.first});
        }


        sort(arr.begin(), arr.end(), greater<pair<int, int>>());


        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/top-k-frequent-elements/)