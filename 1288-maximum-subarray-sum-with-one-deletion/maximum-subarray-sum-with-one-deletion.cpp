class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int noDelete = arr[0];
        int deleteOne = INT_MIN;

        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int previousNoDelete = noDelete;

            // Normal Kadane
            noDelete = max(arr[i], noDelete + arr[i]);

            // Delete current OR deletion already happened
            if (deleteOne == INT_MIN) {
                deleteOne = previousNoDelete;
            } else {
                deleteOne = max(previousNoDelete, deleteOne + arr[i]);
            }

            ans = max({ans, noDelete, deleteOne});
        }

        return ans;
    }
};