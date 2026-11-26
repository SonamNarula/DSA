class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int x : nums) {

            sum += x;

            if (mp.count(sum - goal)) {
                count += mp[sum - goal];
            }

            mp[sum]++;
        }

        return count;
    }
};