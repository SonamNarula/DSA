class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>seen;

         int n = nums.size();

         for(int i = 0; i < n; i++){
            if(seen.count(i)){
                return true;
            }
         }
         return false;
    }
};