class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int maxVowels(string s, int k) {
        int left = 0;
        int vowelCount = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            // Add the new character entering the window
            if (isVowel(s[right])) vowelCount++;

            // Keep window size at most K
            if (right - left + 1 > k) {
                // Remove the character leaving the window
                if (isVowel(s[left])) vowelCount--; // Fixed: was vowelCount++
                left++;
            }

            // Exactly K characters -> evaluate
            if (right - left + 1 == k) {
                ans = max(ans, vowelCount);
            }
        }

        return ans;
    }
};