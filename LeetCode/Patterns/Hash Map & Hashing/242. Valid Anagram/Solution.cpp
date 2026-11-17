class Solution{
    public:
    bool isAnagram(string s, string t){
        // edge cases
        int freq[26] = {0};
        if(s.size()!=t.size()){
            return false;
        }
        for(int i = 0; i < s.size();i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']++;
        }

        // every freq must be 0

        for(int count:freq){
            if(count != 0){
                return false;
            }
        }
        return true;
    }
};