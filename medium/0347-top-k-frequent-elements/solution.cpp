class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();


        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(n + 1);

        for (auto& entry : freq) {

            int element = entry.first;
            int frequency = entry.second;

            bucket[frequency].push_back(element);
        }
        vector<int> ans;

        for (int i = n; i >= 1; i--) {
            for (int num : bucket[i]) {

                ans.push_back(num);


                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};