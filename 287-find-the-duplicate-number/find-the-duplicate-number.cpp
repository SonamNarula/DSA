class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // --------------------------------------------------
        // STEP 1: Find the meeting point of slow and fast
        // --------------------------------------------------
        
        int slow = nums[0];
        int fast = nums[0];

        do {
            // Slow pointer moves one step
            slow = nums[slow];

            // Fast pointer moves two steps
            fast = nums[nums[fast]];

        } while (slow != fast);


        // --------------------------------------------------
        // STEP 2: Find the entrance of the cycle
        // --------------------------------------------------
        // At this point, slow and fast are meeting somewhere
        // inside the cycle.
        //
        // Now start another pointer from the beginning.
        // Move both pointers one step at a time.
        // The point where they meet is the duplicate number.
        // --------------------------------------------------

        int slow2 = nums[0];

        while (slow2 != slow) {
            
            // Move both pointers one step
            slow2 = nums[slow2];
            slow = nums[slow];
        }

        // The meeting point is the duplicate number
        return slow;
    }
};