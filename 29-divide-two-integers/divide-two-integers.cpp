class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow edge case: INT_MIN / -1 = INT_MAX + 1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Work with negative numbers directly to avoid INT_MIN overflow when using abs()
        int a = dividend < 0 ? dividend : -dividend;
        int b = divisor < 0 ? divisor : -divisor;

        int quotient = 0;

        // Exponential search using bit shifts
        while (a <= b) {
            int temp = b;
            int count = 1;

            // Shift left until temp * 2 exceeds 'a' (note: using negative integers)
            // temp >= -1073741824 (-2^30) checks to prevent bit overflow
            while (temp >= -1073741824 && a <= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }

            a -= temp;
            quotient += count;
        }

        return negative ? -quotient : quotient;
    }
};