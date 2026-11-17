class Solution{
    public:
    bool containsDuplicate(vector<int>& arr){

        int n = arr.size();

        unordered_set<int>seen;

        for(int i = 0; i < n; i++){
            if(seen.find(arr[i]) != seen.end()){
                return true;
            }
            seen.insert(arr[i]);
        }
        return false;
    }
};