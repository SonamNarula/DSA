class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // n = 1 or 2 -> only the numbers themselves are possible
        if (n <= 2) return n;

        // find smallest power of 2 greater than n
        int ans = 1;
        while (ans <= n) ans <<= 1;

        return ans;
    }
};