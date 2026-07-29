class Solution {

public:

    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();

        for(int i = 0; i < n; i++) {

            int complement = target - numbers[i];

            int left = i + 1;

            int right = n - 1;

            while(left <= right) {

                int mid = left + (right - left) / 2;

                if(numbers[mid] == complement)

                    return {i + 1, mid + 1};

                else if(numbers[mid] < complement)

                    left = mid + 1;

                else

                    right = mid - 1;

            }

        }

        return {};

    }
};