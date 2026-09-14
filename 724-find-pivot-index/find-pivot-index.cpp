class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n = a.size();
        int sum = 0;

        // Step 1: Calculate total sum of the array
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        int left = 0;

        // Step 2: Iterate to find the pivot index
        for (int i = 0; i < n; i++) {
            int right = sum - left - a[i];

            if (left == right) {
                return i;
            }

            left += a[i];
        }

        return -1;
    }
};