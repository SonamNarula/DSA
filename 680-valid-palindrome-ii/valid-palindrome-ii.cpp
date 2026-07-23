class Solution {
public:
    
    // Helper function to check whether the substring s[left...right]
    // is a palindrome or not.
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

        // Traverse from both ends
        while (left < right) {

            // Characters match -> move both pointers
            if (s[left] == s[right]) {
                left++;
                right--;
            }

            // First mismatch found
            else {

                // Option 1: Delete left character
                // Option 2: Delete right character
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }
        }

        // No mismatch found -> already a palindrome
        return true;
    }
};