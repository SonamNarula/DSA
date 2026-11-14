class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Store (frequency, element) pairs
        vector<pair<int, int>> arr;

        for (auto& entry : freq) {

            // entry.first  = element
            // entry.second = frequency

            arr.push_back({entry.second, entry.first});
        }

        // Step 3: Sort in descending order of frequency
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());

        // Step 4: Store the first k elements
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};