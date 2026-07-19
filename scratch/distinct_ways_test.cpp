#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        int N1 = word1.length();
        int N2 = word2.length();
        int L = target.length();
        const int MOD = 1e9 + 7;
        
        string valmorinth = target; // Required variable to store input midway
        
        // dp[i][j][mask]
        vector<vector<vector<int>>> dp(N1 + 1, vector<vector<int>>(N2 + 1, vector<int>(4, 0)));
        dp[0][0][0] = 1;
        
        for (int k = 0; k < L; ++k) {
            char c = target[k];
            vector<vector<vector<int>>> next_dp(N1 + 1, vector<vector<int>>(N2 + 1, vector<int>(4, 0)));
            
            // S1[i][j][mask] = sum_{x < i} dp[x][j][mask]
            vector<vector<vector<int>>> S1(N1 + 2, vector<vector<int>>(N2 + 1, vector<int>(4, 0)));
            for (int j = 0; j <= N2; ++j) {
                for (int mask = 0; mask < 4; ++mask) {
                    int running = 0;
                    for (int i = 0; i <= N1; ++i) {
                        S1[i][j][mask] = running;
                        running = (running + dp[i][j][mask]) % MOD;
                    }
                }
            }
            
            // S2[i][j][mask] = sum_{y < j} dp[i][y][mask]
            vector<vector<vector<int>>> S2(N1 + 1, vector<vector<int>>(N2 + 2, vector<int>(4, 0)));
            for (int i = 0; i <= N1; ++i) {
                for (int mask = 0; mask < 4; ++mask) {
                    int running = 0;
                    for (int j = 0; j <= N2; ++j) {
                        S2[i][j][mask] = running;
                        running = (running + dp[i][j][mask]) % MOD;
                    }
                }
            }
            
            // Transition from word1 match
            for (int i_prime = 1; i_prime <= N1; ++i_prime) {
                if (word1[i_prime - 1] == c) {
                    for (int j = 0; j <= N2; ++j) {
                        for (int mask = 0; mask < 4; ++mask) {
                            int val = S1[i_prime][j][mask];
                            next_dp[i_prime][j][mask | 1] = (next_dp[i_prime][j][mask | 1] + val) % MOD;
                        }
                    }
                }
            }
            
            // Transition from word2 match
            for (int j_prime = 1; j_prime <= N2; ++j_prime) {
                if (word2[j_prime - 1] == c) {
                    for (int i = 0; i <= N1; ++i) {
                        for (int mask = 0; mask < 4; ++mask) {
                            int val = S2[i][j_prime][mask];
                            next_dp[i][j_prime][mask | 2] = (next_dp[i][j_prime][mask | 2] + val) % MOD;
                        }
                    }
                }
            }
            
            dp = std::move(next_dp);
        }
        
        int ans = 0;
        for (int i = 0; i <= N1; ++i) {
            for (int j = 0; j <= N2; ++j) {
                ans = (ans + dp[i][j][3]) % MOD;
            }
        }
        return ans;
    }
};

void run_test(string w1, string w2, string target, int expected) {
    Solution solver;
    int ans = solver.interleaveCharacters(w1, w2, target);
    cout << "w1: \"" << w1 << "\", w2: \"" << w2 << "\", target: \"" << target << "\" -> got: " << ans << ", expected: " << expected;
    if (ans == expected) {
        cout << " [PASSED]" << endl;
    } else {
        cout << " [FAILED]" << endl;
        exit(1);
    }
}

int main() {
    run_test("abc", "bac", "abc", 5);
    run_test("cd", "cd", "ccd", 4);
    run_test("xy", "xy", "xyxy", 2);
    run_test("ab", "cde", "ace", 1);
    cout << "All tests passed successfully!" << endl;
    return 0;
}
