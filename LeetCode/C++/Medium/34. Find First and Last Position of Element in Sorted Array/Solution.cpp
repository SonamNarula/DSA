
class Solution {
public:

    int firstOccurrence(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                res = mid;
                high = mid - 1;  // Search left
            }

            else if (nums[mid] > target) {
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return res;
    }


    int lastOccurrence(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                res = mid;
                low = mid + 1;  // Search right
            }

            else if (nums[mid] > target) {
                high = mid - 1;
            }

            else {
                low = mid + 1;
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
