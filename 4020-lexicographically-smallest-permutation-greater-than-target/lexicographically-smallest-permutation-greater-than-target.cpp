class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Try making the first difference at position i.
        // We go from right to left so that the common prefix is maximized.
        for (int i = n - 1; i >= 0; i--) {

            // We need the characters of target[0 ... i-1]
            // to be available in s.
            vector<int> temp = freq;
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (temp[x] == 0) {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if (!possible)
                continue;

            // At position i, choose the smallest character
            // strictly greater than target[i].
            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (temp[c] > 0) {

                    string ans = target.substr(0, i);
                    ans += char('a' + c);

                    temp[c]--;

                    // Remaining characters in sorted order
                    for (int x = 0; x < 26; x++) {
                        ans += string(temp[x], char('a' + x));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};