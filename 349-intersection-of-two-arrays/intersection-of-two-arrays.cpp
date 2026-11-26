class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0;
        int j = 0;

        vector<int> ans;

        while (i < a.size() && j < b.size()) {

            if (a[i] == b[j]) {

                // duplicate answer ko avoid karo
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }

                i++;
                j++;
            }

            else if (a[i] < b[j]) {
                i++;
            }

            else {
                j++;
            }
        }

        return ans;
    }
};