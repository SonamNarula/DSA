class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        // Step 1: First non-negative element ka index find karenge
        int split = 0;

        while (split < n && nums[split] < 0) {
            split++;
        }

        vector<int> leftSquares;
        vector<int> rightSquares;

        // Step 2: Negative numbers ko reverse order mein square karenge
        // Isse leftSquares ascending order mein banega
        for (int i = split - 1; i >= 0; i--) {
            leftSquares.push_back(nums[i] * nums[i]);
        }

        // Step 3: Non-negative numbers ko normal order mein square karenge
        // Ye squares already ascending order mein honge
        for (int i = split; i < n; i++) {
            rightSquares.push_back(nums[i] * nums[i]);
        }

        // Step 4: Dono sorted arrays ko merge karenge
        vector<int> result;

        int i = 0; // leftSquares ka pointer
        int j = 0; // rightSquares ka pointer

        // Dono arrays ke elements compare karenge
        while (i < leftSquares.size() && j < rightSquares.size()) {

            if (leftSquares[i] < rightSquares[j]) {
                result.push_back(leftSquares[i]);
                i++;
            } else {
                result.push_back(rightSquares[j]);
                j++;
            }
        }

        // Agar left array mein elements bache hain
        while (i < leftSquares.size()) {
            result.push_back(leftSquares[i]);
            i++;
        }

        // Agar right array mein elements bache hain
        while (j < rightSquares.size()) {
            result.push_back(rightSquares[j]);
            j++;
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna