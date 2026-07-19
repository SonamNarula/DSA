class Solution {
public:
    bool hasTripletSum(vector<int> &arr, int target) {

        // Size of the array
        int n = arr.size();

        // Sort the array so that we can use the two-pointer approach
        sort(arr.begin(), arr.end());

        // Fix the first element of the triplet
        for (int i = 0; i < n - 2; i++) {

            // Two pointers for the remaining part of the array
            int left = i + 1;
            int right = n - 1;

            // Find two numbers whose sum with arr[i] equals target
            while (left < right) {

                // Current triplet sum
                int sum = arr[i] + arr[left] + arr[right];

                // Triplet found
                if (sum == target) {
                    return true;
                }

                // Sum is too small, move left pointer to increase the sum
                else if (sum < target) {
                    left++;
                }

                // Sum is too large, move right pointer to decrease the sum
                else {
                    right--;
                }
            }
        }

        // No valid triplet found
        return false;
    }
};