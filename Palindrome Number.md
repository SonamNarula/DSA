## 01. Palindrome Number

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/palindrome0746/1)

### Problem Description

**Task:** You are given an integer n. Your task is to find if it is a palindrome. Examples:Input: n = 555

#### Examples

##### Example 1

- **Output:**
```text
trueExplanation: if number is palindrome, mainly ignore sign.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(d), d is number of digits in nAuxiliary Space: O(1)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-15 07:25:38
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
public:
    bool isPalindrome(int n) {

        // Ignore negative sign
        if(n < 0){
            n = -n;
        }

        // Numbers ending with 0 cannot be palindrome (except 0)
        if(n % 10 == 0 && n != 0){
            return false;
        }

        // Store reversed half of the number
        int reversed = 0;

        // Reverse digits until we reach the middle
        while(n > reversed){

            // Extract last digit and add it to reversed
            reversed = reversed * 10 + (n % 10);

            // Remove last digit from n
            n = n / 10;
        }

        // Check for even and odd number of digits
        return (n == reversed || n == reversed / 10);
    }
};
```

*Generated on: 15/11/2026, 07:26:02*