class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> arr;

        for(int i = 0; i < nums.size(); i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        int n = arr.size();

        for(int i = 0; i < n; i++) {

            int complement = target - arr[i].first;

            int low = i + 1;
            int high = n - 1;

            while(low <= high) {

                int mid = low + (high - low) / 2;

                if(arr[mid].first == complement)
                    return {arr[i].second, arr[mid].second};

                if(arr[mid].first < complement)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return {};
    }
};