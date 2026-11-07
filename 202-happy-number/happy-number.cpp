class Solution {
public:

    // Calculates sum of squares of all digits
    int getNext(int n) {

        int sum = 0;

        while (n > 0) {

            int digit = n % 10;       //  last digit
            sum += digit * digit;     // Add its square

            n /= 10;                  // Remove last digit
        }

        return sum;
    }

    bool isHappy(int n) {

        int slow = n;  // Moves one step
        int fast = n;  // Moves two steps

        do {

            slow = getNext(slow);

            fast = getNext(getNext(fast));

        } while (slow != fast);  // Continue until they meet

        return slow == 1;  // Happy if cycle meets at 1
    }
};