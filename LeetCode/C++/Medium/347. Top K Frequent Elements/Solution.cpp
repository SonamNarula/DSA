class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create n+1 empty buckets
        // Index represents frequency
        vector<vector<int>> bucket(n + 1);

        // Step 3: Place elements into their frequency buckets
        for (auto& entry : freq) {

            int element = entry.first;
            int frequency = entry.second;

            bucket[frequency].push_back(element);
        }

        // Step 4: Traverse buckets from highest frequency
        vector<int> ans;

        for (int i = n; i >= 1; i--) {

            // Check all elements having frequency i
            for (int num : bucket[i]) {

                ans.push_back(num);

                // Stop when we have k elements
                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};