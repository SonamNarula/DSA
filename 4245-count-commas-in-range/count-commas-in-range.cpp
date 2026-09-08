class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;

        // 1,000 to 999,999
        if (n >= 1000) {
            ans += min(n, 999999) - 1000 + 1;
        }

        // 1,000,000 to 999,999,999
        if (n >= 1000000) {
            ans += 2LL * (min(n, 999999999) - 1000000 + 1);
        }

        // 1,000,000,000 onwards
        if (n >= 1000000000) {
            ans += 3LL * (n - 1000000000 + 1);
        }

        return ans;
    }
};
