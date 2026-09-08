class Solution {
public:
    int longestKSubstr(string s, int k) {

        unordered_map<char, int> freq;

        int left = 0;

        // -1 because no valid substring may exist
        int ans = -1;

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            freq[s[right]]++;

            // If distinct characters exceed k,
            // shrink the window
            while (freq.size() > k) {

                freq[s[left]]--;

                // Character completely removed
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            // IMPORTANT:
            // We need EXACTLY k distinct characters
            if (freq.size() == k) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};