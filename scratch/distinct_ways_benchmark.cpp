#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

// Old TLE version
class SolutionTLE {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        int N1 = word1.length();
        int N2 = word2.length();
        int L = target.length();
        const int MOD = 1e9 + 7;
        
        vector<vector<vector<int>>> dp(N1 + 1, vector<vector<int>>(N2 + 1, vector<int>(4, 0)));
        dp[0][0][0] = 1;
        
        for (int k = 0; k < L; ++k) {
            char c = target[k];
            vector<vector<vector<int>>> next_dp(N1 + 1, vector<vector<int>>(N2 + 1, vector<int>(4, 0)));
            
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

// Optimized version
class SolutionOptimized {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        int N1 = word1.length();
        int N2 = word2.length();
        int L = target.length();
        const int MOD = 1e9 + 7;
        
        string valmorinth = target;
        
        // Statically sized arrays in buffer
        static int dp_buf1[105][105][4];
        static int dp_buf2[105][105][4];
        static int S1[105][105][4];
        static int S2[105][105][4];
        
        int (*dp)[105][4] = dp_buf1;
        int (*next_dp)[105][4] = dp_buf2;
        
        // Initialize only the active size of dp
        for (int i = 0; i <= N1; ++i) {
            for (int j = 0; j <= N2; ++j) {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 0;
            }
        }
        dp[0][0][0] = 1;
        
        for (int k = 0; k < L; ++k) {
            char c = target[k];
            
            // Reset next_dp
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
            for (int i_prime = 1; i_prime <= N1; ++i_prime) {
                if (word1[i_prime - 1] == c) {
                    for (int j = 0; j <= N2; ++j) {
                        for (int mask = 0; mask < 4; ++mask) {
                            int val = S1[i_prime][j][mask];
                            if (val > 0) {
                                int& next_val = next_dp[i_prime][j][mask | 1];
                                next_val += val;
                                if (next_val >= MOD) next_val -= MOD;
                            }
                        }
                    }
                }
            }
            
            // Transition Word2
            for (int j_prime = 1; j_prime <= N2; ++j_prime) {
                if (word2[j_prime - 1] == c) {
                    for (int i = 0; i <= N1; ++i) {
                        for (int mask = 0; mask < 4; ++mask) {
                            int val = S2[i][j_prime][mask];
                            if (val > 0) {
                                int& next_val = next_dp[i][j_prime][mask | 2];
                                next_val += val;
                                if (next_val >= MOD) next_val -= MOD;
                            }
                        }
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

int main() {
    string w1 = string(100, 'a');
    string w2 = string(100, 'a');
    string target = string(100, 'a');
    
    // Warmup
    SolutionTLE solverTLE;
    SolutionOptimized solverOpt;
    cout << "TLE ans: " << solverTLE.interleaveCharacters(w1, w2, target) << endl;
    cout << "Opt ans: " << solverOpt.interleaveCharacters(w1, w2, target) << endl;
    
    auto t1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < 50; ++i) {
        solverTLE.interleaveCharacters(w1, w2, target);
    }
    auto t2 = chrono::high_resolution_clock::now();
    cout << "TLE version (50 runs): " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " ms" << endl;
    
    auto t3 = chrono::high_resolution_clock::now();
    for (int i = 0; i < 50; ++i) {
        solverOpt.interleaveCharacters(w1, w2, target);
    }
    auto t4 = chrono::high_resolution_clock::now();
    cout << "Optimized version (50 runs): " << chrono::duration_cast<chrono::milliseconds>(t4 - t3).count() << " ms" << endl;
    
    return 0;
}
