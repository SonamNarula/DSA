class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        // Store the final answer
        vector<int> ans(n, 1);

        // Step 1: Calculate prefix products
        // ans[i] stores product of all elements to the left

        int prefix = 1;

        for(int i = 0; i < n; i++){

            // Store left product at current index
            ans[i] = prefix;

            // Update prefix for the next index
            prefix = prefix * nums[i];
        }

        // Step 2: Calculate suffix products
        // Multiply right product with the existing prefix

        int suffix = 1;

        for(int i = n - 1; i >= 0; i--){

            // Multiply left product and right product
            ans[i] = ans[i] * suffix;

            // Update suffix for the next index
            suffix = suffix * nums[i];
        }

        // Return the final answer
        return ans;
    }
};