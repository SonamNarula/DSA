class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& nums, int k) {
        int n = nums.size();
        int m = nums[0].size();

        vector<int>v;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(nums[i][j]);
            }
        }

        int x = k%(n*m);

        vector<int>w;

        for(int i=(n*m)-x;i<n*m;i++){
            w.push_back(v[i]);
        }
        for(int i=0;i<(n*m)-x;i++){
            w.push_back(v[i]);
        }


        int y = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums[i][j]=w[y];
                y++;
            }
        }

        return nums;
    }
};