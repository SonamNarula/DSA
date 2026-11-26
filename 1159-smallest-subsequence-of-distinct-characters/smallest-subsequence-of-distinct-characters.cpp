class Solution {
public:
    string smallestSubsequence(string s) {

        // last[ch] = character ki last occurrence kis index par hai
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        // visited[ch] = kya ye character already answer (stack) me hai?
        vector<bool> visited(26, false);

        stack<char> st;

        // String ko left -> right traverse karenge
        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Agar character already stack me hai,
            // toh dobara add nahi karna
            if (visited[ch - 'a'])
                continue;

            // Jab tak:
            // 1. Stack empty nahi hai
            // 2. Current character chhota hai stack top se
            // 3. Stack top future me fir se mil jayega
            // tab tak pop karte raho
            while (!st.empty() &&
                   ch < st.top() &&
                   last[st.top() - 'a'] > i) {

                // Pop karte hi visited false karna zaroori hai,
                // taaki future me is character ko fir add kar saken
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            // Current character answer me add karo
            st.push(ch);
            visited[ch - 'a'] = true;
        }

        // Stack ko string me convert karna
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Stack se reverse order me characters mile,
        // isliye reverse karna padega
        reverse(ans.begin(), ans.end());

        return ans;
    }
};