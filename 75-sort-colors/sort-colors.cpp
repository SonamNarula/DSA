class Solution {

public:

    void sortColors(vector<int>& nums) {

        int zero = 0;

        int one = 0;

        int two = 0;

        for(int num : nums){

            if(num == 0)

                zero++;

            else if(num == 1)

                one++;

            else

                two++;

        }

        int index = 0;

        while(zero--)

            nums[index++] = 0;

        while(one--)

            nums[index++] = 1;

        while(two--)

            nums[index++] = 2;

    }

};