class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                int len=j-i+1;
                if(len<=r && len>=l && sum>0)
                    res=min(res,sum);
                else if(len>r)
                    break;
            }
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
};