class Solution {
public:
    int expand(string& s, int left, int right) {
        while (left >= 0 &&
               right < (int)s.size() &&
               s[left] == s[right]) {
            left--;
            right++;
        }


        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            int oddLen = expand(s, i, i);
            int evenLen = expand(s, i, i + 1);

            int len = max(oddLen, evenLen);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};