class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";

        int ones = 0;
        for (char c : s) ones += c == '1';

        int best = 0;

        int i = 0;
        int prevZero = 0;

        while (i < t.size()) {
            if (t[i] == '0') {
                int j = i;
                while (j < t.size() && t[j] == '0') j++;
                prevZero = j - i;
                i = j;
            } else {
                int j = i;
                while (j < t.size() && t[j] == '1') j++;

                if (i != 0 && j != t.size()) {
                    int k = j;
                    while (k < t.size() && t[k] == '0') k++;
                    best = max(best, prevZero + (k - j));
                }

                i = j;
            }
        }

        return ones + best;
    }
};