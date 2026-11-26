class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        string ans = "";
        int bestLen = INT_MAX;

        for(int i = 0; i < n; i++) {
            
            int ones = 0;

            for(int j = i; j < n; j++) {
                
                if(s[j] == '1')
                    ones++;

                // More than k ones -> cannot be beautiful
                if(ones > k)
                    break;

                // Exactly k ones -> beautiful substring
                if(ones == k) {
                    
                    string curr = s.substr(i, j - i + 1);
                    
                    // Shorter substring is better
                    if(curr.size() < bestLen) {
                        bestLen = curr.size();
                        ans = curr;
                    }
                    
                    // Same length -> lexicographically smaller is better
                    else if(curr.size() == bestLen && curr < ans) {
                        ans = curr;
                    }

                    // No need to extend because adding another character
                    // will only make the substring longer
                    break;
                }
            }
        }

        return ans;
    }
};