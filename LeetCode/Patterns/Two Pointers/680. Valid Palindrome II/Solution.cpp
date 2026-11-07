class Solution {
public:

    // Checks whether substring from left to right is palindrome
    bool isPalindrome(string &s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            if (s[left] != s[right]) {

                // Option 1: Delete left character
                // Option 2: Delete right character
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }

            left++;
            right--;
        }

        return true;
    }
};