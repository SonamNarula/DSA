class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;

        int n = nums.size();

        for(int i = 0; i < n-2;i++)
        {
            for(int j = i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    int sum = nums[i] + nums[j]+nums[k];

                    if(sum == 0){
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return ans;
        
    }
};
