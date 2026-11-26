class Solution {
public:

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' ||
               ch == 'i' || ch == 'o' ||
               ch == 'u';
    }

    int maxVowels(string s, int k) {

        int left = 0;
        int count = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add incoming character
            if (isVowel(s[right])) {
                count++;
            }

            // Maintain window size k
            if (right - left + 1 > k) {

                // Remove outgoing character
                if (isVowel(s[left])) {
                    count--;
                }

                left++;
            }

            // Update answer when window reaches size k
            if (right - left + 1 == k) {
                ans = max(ans, count);
            }
        }

        return ans;
    }
};