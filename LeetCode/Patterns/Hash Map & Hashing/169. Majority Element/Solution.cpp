class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        for (int num : nums) {

            // No active votes: select a new candidate
            if (count == 0) {
                candidate = num;
            }

            // Same number supports the candidate;
            // different number cancels one vote
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};