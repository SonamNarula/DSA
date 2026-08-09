class Solution {
public:
    int smallestNumber(int n, int t) {
        
        // Start checking from n
        while (true) {
            int num = n;
            int product = 1;
            
            // Calculate product of digits
            while (num > 0) {
                int digit = num % 10;
                product *= digit;
                num /= 10;
            }
            
            // If digit product is divisible by t
            if (product % t == 0) {
                return n;
            }
            
            // Try the next number
            n++;
        }
    }
};