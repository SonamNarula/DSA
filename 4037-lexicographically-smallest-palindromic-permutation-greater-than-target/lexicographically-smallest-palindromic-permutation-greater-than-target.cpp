class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int halfLen = n / 2;

        // Frequency
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        // Check whether palindrome is possible
        int odd = 0;
        char center = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                center = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available for LEFT half
        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = freq[i] / 2;

        // Build palindrome from left half
        auto build = [&](const string& left) {
            string ans = left;

            if (n % 2)
                ans += center;

            string rev = left;
            reverse(rev.begin(), rev.end());

            ans += rev;

            return ans;
        };

        // We only compare the first half.
        string targetLeft = target.substr(0, halfLen);

        // ---------------------------------------------------------
        // 1. Try using targetLeft itself
        // ---------------------------------------------------------

        vector<int> cnt = half;
        bool possible = true;

        for (char c : targetLeft) {
            int x = c - 'a';

            if (cnt[x] == 0) {
                possible = false;
                break;
            }

            cnt[x]--;
        }

        if (possible) {
            string candidate = build(targetLeft);

            if (candidate > target)
                return candidate;
        }

        // ---------------------------------------------------------
        // 2. Find the smallest LEFT half > targetLeft
        // ---------------------------------------------------------

        // We change the rightmost possible position.
        for (int i = halfLen - 1; i >= 0; i--) {

            // Characters available after matching targetLeft[0..i-1]
            vector<int> rem = half;
            bool prefixPossible = true;

            for (int j = 0; j < i; j++) {
                int x = targetLeft[j] - 'a';

                if (rem[x] == 0) {
                    prefixPossible = false;
                    break;
                }

                rem[x]--;
            }

            if (!prefixPossible)
                continue;

            int cur = targetLeft[i] - 'a';

            // Pick smallest character strictly greater
            for (int c = cur + 1; c < 26; c++) {

                if (rem[c] == 0)
                    continue;

                rem[c]--;

                string left = targetLeft.substr(0, i);
                left += char('a' + c);

                // Fill remaining positions smallest possible
                for (int x = 0; x < 26; x++) {
                    left += string(rem[x], char('a' + x));
                }

                return build(left);
            }
        }

        return "";
    }
};