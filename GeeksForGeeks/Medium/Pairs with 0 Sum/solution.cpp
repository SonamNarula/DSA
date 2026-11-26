class Solution {
public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        int n = arr.size();

        // Sort the array so we can use two pointers
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == 0) {
                // Store the unique pair
                ans.push_back({arr[left], arr[right]});

                int leftVal = arr[left];
                int rightVal = arr[right];

                // Skip duplicate values on the left
                while (left < right && arr[left] == leftVal) {
                    left++;
                }

                // Skip duplicate values on the right
                while (left < right && arr[right] == rightVal) {
                    right--;
                }
            }
            else if (sum < 0) {
                // Sum is too small; move left to a larger value
                left++;
            }
            else {
                // Sum is too large; move right to a smaller value
                right--;
            }
        }

        return ans;
    }
};