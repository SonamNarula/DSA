class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxFreq = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            // Highest frequency character inside window.
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            // Characters that must be replaced.
            int replacements = (right - left + 1) - maxFreq;
            while (replacements > k) {
                freq[s[left] - 'A']--;
                left++;
                replacements = (right - left + 1) - maxFreq;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};