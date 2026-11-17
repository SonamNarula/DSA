class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int candidate = 0;
        int count = 0;

        for (int i = 0; i < n; i++ ) {

            // No active votes: select a new candidate
            if (count == 0) {
                candidate = nums[i];
            }

            // Same number supports the candidate;
            // different number cancels one vote
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};