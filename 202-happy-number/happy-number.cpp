class Solution {
public:

    // Function to calculate sum of squares of digits
    int getNext(int n) {

        int sum = 0;

        while (n > 0) {

            // Last digit nikalna
            int digit = n % 10;

            // Digit ka square sum mein add karna
            sum += digit * digit;

            // Last digit remove karna
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        // -----------------------------------------
        // STEP 1: Slow and Fast pointers
        // -----------------------------------------
        // Slow → ek number aage jayega
        // Fast → do numbers aage jayega
        //
        // Agar number Happy hai:
        // sequence eventually 1 par pahunch jayegi.
        //
        // Agar Happy nahi hai:
        // sequence kisi cycle mein fas jayegi.
        // -----------------------------------------

        int slow = n;
        int fast = n;

        do {

            // Slow moves ONE step
            slow = getNext(slow);

            // Fast moves TWO steps
            fast = getNext(getNext(fast));

        } while (slow != fast);


        // -----------------------------------------
        // STEP 2: Check where the cycle ended
        // -----------------------------------------
        // Agar meeting point 1 hai,
        // number HAPPY hai.
        //
        // Agar meeting point 1 nahi hai,
        // number kisi unwanted cycle mein fas gaya.
        // -----------------------------------------

        return slow == 1;
    }
};