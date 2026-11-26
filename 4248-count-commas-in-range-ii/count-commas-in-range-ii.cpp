class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // Numbers with 4-6 digits
        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            // Range with the current number of commas:
            // [start, start * 1000 - 1]
            long long end = start * 1000 - 1;

            if (end > n)
                end = n;

            ans += (end - start + 1) * commas;

            // Move to next 3-digit block
            start *= 1000;
            commas++;
        }

        return ans;
    }
};