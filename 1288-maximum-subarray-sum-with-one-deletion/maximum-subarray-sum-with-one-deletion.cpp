class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        // bestEnding = maximum sum of a subarray
        // ending exactly at the current index
        // WITHOUT deleting any element
        int bestEnding = arr[0];

        // bestDeleted = maximum sum of a subarray
        // ending exactly at the current index
        // WITH one element already deleted
        int bestDeleted = INT_MIN;

        // Maximum answer found so far
        int ans = arr[0];

        for (int i = 1; i < n; i++) {

            // Option 1:
            // Continue the previous subarray without deleting anything
            int v1 = bestEnding + arr[i];

            // Option 2:
            // Start a completely new subarray from arr[i]
            int v2 = arr[i];

            // For the state WITHOUT deletion:
            // Either extend the previous subarray
            // OR start fresh
            int newBest = max(v1, v2);

            // Now calculate the state WITH one deletion.
            //
            // Option 1:
            // Delete the CURRENT element.
            //
            // bestEnding is the best sum before arr[i],
            // so we simply don't add arr[i].
            int v3 = bestEnding;

            // Option 2:
            // We have ALREADY deleted one element earlier,
            // so continue that subarray by adding arr[i].
int v4 = INT_MIN;

if (bestDeleted != INT_MIN) {
    v4 = bestDeleted + arr[i];
}

            // Take the better option
            int newDeleted = max(v3, v4);

            // Update both states
            bestEnding = newBest;
            bestDeleted = newDeleted;

            // The answer can come from either:
            // - a subarray with no deletion
            // - a subarray with one deletion
            ans = max(ans, max(bestEnding, bestDeleted));
        }

        return ans;
    }
};