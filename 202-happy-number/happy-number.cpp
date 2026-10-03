class Solution {
public:
    int nextNumber(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = nextNumber(n);
        int fast = nextNumber(nextNumber(n));
        while (slow != fast) {
            slow = nextNumber(slow);             // 1 state
            fast = nextNumber(nextNumber(fast)); // 2 states
        }
        return slow == 1;
    }
};