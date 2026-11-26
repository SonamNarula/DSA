class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false, hasEven = false;
        int mn = INT_MAX;

        for (int x : nums1) {
            mn = min(mn, x);

            if (x % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        // Already uniform
        if (!hasOdd || !hasEven)
            return true;

        // Mixed parity: possible only if smallest element is odd
        return mn % 2 == 1;
    }
};