class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        // Answer array ka size same hoga as nums
        vector<int> ans(n);

        // 2 pointers:
        // left -> array ke starting element par
        // right -> array ke last element par
        int left = 0;
        int right = n - 1;

        // Hum answer ko RIGHT se LEFT fill karenge
        // Kyunki humein sabse bada square pehle mil raha hai
        for(int i = n - 1; i >= 0; i--) {

            // Left aur right dono ends ke elements ka
            // absolute value compare karo
            if(abs(nums[left]) > abs(nums[right])) {

                // Left wala bada hai
                // Uska square answer ke current last position par daalo
                ans[i] = nums[left] * nums[left];

                // Left pointer ko aage badhao
                left++;
            }

            else {

                // Right wala bada hai
                // Uska square answer ke current last position par daalo
                ans[i] = nums[right] * nums[right];

                // Right pointer ko peeche lao
                right--;
            }
        }

        // Sorted squares return karo
        return ans;
    }
};