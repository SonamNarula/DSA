class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();

    // Step 1: Array ko sort karenge
    sort(nums.begin(), nums.end());

    // Step 2: Initial closest sum set karenge
    int closestSum = nums[0] + nums[1] + nums[2];

    // Step 3: Ek element fix karenge
    for (int i = 0; i < n - 2; i++) {

        // Step 4: Two pointers initialize karenge
        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            // Current three elements ka sum
            int sum = nums[i] + nums[left] + nums[right];

            // Check karo current sum target ke closer hai ya nahi
            if (abs(sum - target) <
                abs(closestSum - target)) {
                closestSum = sum;
            }

            // Exact target mil gaya
            if (sum == target) {
                return sum;
            }

            // Sum chhota hai, toh increase karenge
            else if (sum < target) {
                left++;
            }

            // Sum bada hai, toh decrease karenge
            else {
                right--;
            }
        }
    }

    return closestSum;
}
};