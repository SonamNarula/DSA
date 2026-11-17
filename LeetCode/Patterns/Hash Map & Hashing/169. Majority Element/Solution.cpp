class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++; // 1. Increment the count of the element nums[i]
            
            if (freq[nums[i]] > n / 2) { // 2. Check the element's frequency
                return nums[i]; // 3. Return the element itself
            }
        }
        
        return -1; // 4. Return a valid integer fallback
    }
};