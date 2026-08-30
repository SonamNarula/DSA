class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;

            if (nums[i] > nums[mx])
                mx = i;
        }

        int left = min(mn, mx);
        int right = max(mn, mx);

        // 1. Both from front
        int front = right + 1;

        // 2. Both from back
        int back = n - left;

        // 3. One from front, one from back
        int both = (left + 1) + (n - right);

        return min({front, back, both});
    }
};