class Solution {
public:

    // Ye function check karega ki given range [left...right]
    // palindrome hai ya nahi
    bool checkPalindrome(string &s, int left, int right) {

        // Jab tak left aur right cross nahi karte
        while(left < right) {

            // Agar dono characters different hain,
            // toh ye substring palindrome nahi hai
            if(s[left] != s[right])
                return false;

            // Characters same hain,
            // toh dono pointers ko andar move karo
            left++;
            right--;
        }

        // Pura range palindrome hai
        return true;
    }


    bool validPalindrome(string s) {

        // Two pointers:
        // left -> string ke beginning se
        // right -> string ke end se
        int left = 0;
        int right = s.size() - 1;

        // Dono pointers ko compare karte rahenge
        while(left < right) {

            // Agar characters same hain,
            // toh normal palindrome ki tarah aage badho
            if(s[left] == s[right]) {

                left++;
                right--;
            }

            // Agar characters different hain,
            // toh ek character delete karna padega
            else {

                // Ab hamare paas sirf ONE deletion allowed hai.
                //
                // Do possibilities hain:
                //
                // 1. left character delete karo
                //    => left + 1 se check karo
                //
                // 2. right character delete karo
                //    => right - 1 se check karo
                //
                // Agar in dono mein se KISI EK case mein
                // palindrome ban gaya, answer true hoga.

                return checkPalindrome(s, left + 1, right) ||
                       checkPalindrome(s, left, right - 1);
            }
        }

        // Agar poori string mein koi mismatch nahi mila,
        // toh already palindrome hai
        return true;
    }
};