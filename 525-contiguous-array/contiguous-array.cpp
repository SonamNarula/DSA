class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        // prefixSum -> first index where it appeared
        unordered_map<int, int> mp;

        // Prefix sum 0 index -1 par maan rahe hain
        mp[0] = -1;

        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {

            // 0 ko -1 aur 1 ko +1 maanenge
            if (nums[i] == 0) {
                sum -= 1;
            } else {
                sum += 1;
            }

            // Agar same prefix sum pehle aa chuka hai
            if (mp.count(sum)) {

                // Current index - first index
                // = subarray ki length
                int len = i - mp[sum];

                maxLen = max(maxLen, len);

            } else {

                // Pehli baar mila hai,
                // sirf first index store karo
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};