class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++) {
            long long prod=1,l=nums[i],g=nums[i];
            for(int j=i;j<n;j++) {
                prod*=nums[j];
                l=lcm(l,nums[j]);
                g=gcd(g,nums[j]);
                if(prod==l*g) {
                    ans=max(ans,j-i+1);
                }
                if(prod>l*g) {
                    break;
                }
            }
        }
        return ans;
    }
};