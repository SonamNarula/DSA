class Solution {
public:
    // Find first occurrence
    int firstOccurrence(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int res = -1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                res = mid;
                end = mid - 1; // Search left
            } else if (nums[mid] < target) {
                start = mid + 1; // Search right
            } else {
                end = mid - 1; // Search left
            }
        }

        return res;
    }

    // Find last occurrence
    int lastOccurrence(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int res = -1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                res = mid;
                start = mid + 1; // Search right
            } else if (nums[mid] < target) {
                start = mid + 1; // Search right
            } else {
                end = mid - 1; // Search left
            }
        }

        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOccurrence(nums, target);
        int last = lastOccurrence(nums, target);

        return {first, last};
    }
};