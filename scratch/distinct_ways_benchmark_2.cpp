#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

// Version with unrolled masks and index precomputation
class SolutionSuperOptimized {
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
            
            // Transition Word1 using precomputed positions
            for (int i_prime : pos1[char_idx]) {
                for (int j = 0; j <= N2; ++j) {
                    // Unrolled mask loop for mask | 1
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
            
            // Transition Word2 using precomputed positions
            for (int j_prime : pos2[char_idx]) {
                for (int i = 0; i <= N1; ++i) {
                    // Unrolled mask loop for mask | 2
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

int main() {
    string w1 = "abc";
    string w2 = "bac";
    string target = "abc";
    
    SolutionSuperOptimized solver;
    cout << "Correctness test Ex 1: " << solver.interleaveCharacters(w1, w2, target) << " (Expected: 5)" << endl;
    
    // Performance test
    w1 = string(100, 'a');
    w2 = string(100, 'a');
    target = string(100, 'a');
    
    auto t1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < 500; ++i) {
        solver.interleaveCharacters(w1, w2, target);
    }
    auto t2 = chrono::high_resolution_clock::now();
    cout << "Super Optimized version (500 runs): " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " ms" << endl;
    
    return 0;
}
