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
        
        // Stack-allocated arrays to avoid heap overhead and keep thread/run safety
        int dp_buf1[105][105][4];
        int dp_buf2[105][105][4];
        int S1[105][105][4];
        int S2[105][105][4];
        
        int (*dp)[105][4] = dp_buf1;
        int (*next_dp)[105][4] = dp_buf2;
        
        // Initialize the active region of dp
        for (int i = 0; i <= N1; ++i) {
            for (int j = 0; j <= N2; ++j) {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 0;
            }
        }
        dp[0][0][0] = 1;
        
        // Precompute character positions (1-based indices)
        vector<int> pos1[26];
        for (int i = 0; i < N1; ++i) {
            pos1[word1[i] - 'a'].push_back(i + 1);
        }
        
        vector<int> pos2[26];
        for (int j = 0; j < N2; ++j) {
            pos2[word2[j] - 'a'].push_back(j + 1);
        }
        
        for (int k = 0; k < L; ++k) {
            char c = target[k];
            int char_idx = c - 'a';
            
            // Reset next_dp active region
            for (int i = 0; i <= N1; ++i) {
                for (int j = 0; j <= N2; ++j) {
                    next_dp[i][j][0] = next_dp[i][j][1] = next_dp[i][j][2] = next_dp[i][j][3] = 0;
                }
            }
            
            // Compute S1
            for (int j = 0; j <= N2; ++j) {
                for (int mask = 0; mask < 4; ++mask) {
                    int running = 0;
                    for (int i = 0; i <= N1; ++i) {
                        S1[i][j][mask] = running;
                        running += dp[i][j][mask];
                        if (running >= MOD) running -= MOD;
                    }
                }
            }
            
            // Compute S2
            for (int i = 0; i <= N1; ++i) {
                for (int mask = 0; mask < 4; ++mask) {
                    int running = 0;
                    for (int j = 0; j <= N2; ++j) {
                        S2[i][j][mask] = running;
                        running += dp[i][j][mask];
                        if (running >= MOD) running -= MOD;
                    }
                }
            }
            
            // Transition Word1
            for (int i_prime : pos1[char_idx]) {
                for (int j = 0; j <= N2; ++j) {
                    int val0 = S1[i_prime][j][0];
                    if (val0 > 0) {
                        int& next_val = next_dp[i_prime][j][1];
                        next_val += val0;
                        if (next_val >= MOD) next_val -= MOD;
                    }
                    int val1 = S1[i_prime][j][1];
                    if (val1 > 0) {
                        int& next_val = next_dp[i_prime][j][1];
                        next_val += val1;
                        if (next_val >= MOD) next_val -= MOD;
                    }
                    int val2 = S1[i_prime][j][2];
                    if (val2 > 0) {
                        int& next_val = next_dp[i_prime][j][3];
                        next_val += val2;
                        if (next_val >= MOD) next_val -= MOD;
                    }
                    int val3 = S1[i_prime][j][3];
                    if (val3 > 0) {
                        int& next_val = next_dp[i_prime][j][3];
                        next_val += val3;
                        if (next_val >= MOD) next_val -= MOD;
                    }
                }
            }
            
            // Transition Word2
            for (int j_prime : pos2[char_idx]) {
                for (int i = 0; i <= N1; ++i) {
                    int val0 = S2[i][j_prime][0];
                    if (val0 > 0) {
                        int& next_val = next_dp[i][j_prime][2];
                        next_val += val0;
                        if (next_val >= MOD) next_val -= MOD;
                    }
                    int val1 = S2[i][j_prime][1];
                    if (val1 > 0) {
                        int& next_val = next_dp[i][j_prime][3];
                        next_val += val1;
                        if (next_val >= MOD) next_val -= MOD;
                    }
                    int val2 = S2[i][j_prime][2];
                    if (val2 > 0) {
                        int& next_val = next_dp[i][j_prime][2];
                        next_val += val2;
                        if (next_val >= MOD) next_val -= MOD;
                    }
                    int val3 = S2[i][j_prime][3];
                    if (val3 > 0) {
                        int& next_val = next_dp[i][j_prime][3];
                        next_val += val3;
                        if (next_val >= MOD) next_val -= MOD;
                    }
                }
            }
            
            // Pointer swap
            swap(dp, next_dp);
        }
        
        int ans = 0;
        for (int i = 0; i <= N1; ++i) {
            for (int j = 0; j <= N2; ++j) {
                ans += dp[i][j][3];
                if (ans >= MOD) ans -= MOD;
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
    cout << "All final tests passed successfully!" << endl;
    return 0;
}
