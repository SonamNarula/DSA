class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int x : nums) {

            // Count odd numbers
            if (x % 2 == 1) {
                sum++;
            }

            // Need previous prefix = sum - k
            if (mp.count(sum - k)) {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }
};