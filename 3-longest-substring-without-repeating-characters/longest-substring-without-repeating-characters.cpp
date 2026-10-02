class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            // Duplicate means window is invalid.
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }
            // Window now has all unique characters.
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};