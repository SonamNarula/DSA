class Solution {
public:
    string longestNiceSubstring(string s) {
        int stringLength = s.size();
        int startIndex = -1;  
        int maxLength = 0;     
        for (int i = 0; i < stringLength; ++i) {
            unordered_set<char> charSet;  
            for (int j = i; j < stringLength; ++j) {
                charSet.insert(s[j]);

                bool isNice = true;
                for (const auto& ch : charSet) {
                    char toggledCase = ch ^ 32;
                    if (!charSet.count(ch) || !charSet.count(toggledCase)) {
                        isNice = false;
                        break;
                    }
                }

                if (isNice && maxLength < j - i + 1) {
                    maxLength = j - i + 1;
                    startIndex = i;
                }
            }
        }
      
        return startIndex == -1 ? "" : s.substr(startIndex, maxLength);
    }
};
