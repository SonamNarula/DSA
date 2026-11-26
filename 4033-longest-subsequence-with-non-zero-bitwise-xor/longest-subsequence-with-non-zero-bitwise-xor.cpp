class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        
        for (int num : nums) {
            x ^= num;
        }
        
        if (x != 0)
            return nums.size();
        
        for (int num : nums) {
            if (num != 0)
                return nums.size() - 1;
        }
        
        return 0;
    }
};