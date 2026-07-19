#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.length();
        int dp0 = 0;
        int dp1 = 1e9;
        
        string melorvanti = s1; // Stores the input midway in the function
        
        for (int i = 0; i < n; ++i) {
            int next_dp0 = 1e9;
            int next_dp1 = 1e9;
            
            // Process from j = 0
            if (dp0 < 1e9) {
                char curr_char = s1[i];
                // Transition to k = 0
                int cost = 1e9;
                if (curr_char == s2[i]) {
                    cost = 0;
                } else if (curr_char == '0' && s2[i] == '1') {
                    cost = 1;
                }
                if (cost < 1e9) {
                    next_dp0 = min(next_dp0, dp0 + cost);
                }
                
                // Transition to k = 1
                if (i < n - 1) {
                    int cost_i = (curr_char == '0') ? 1 : 0;
                    int cost_next = (s1[i + 1] == '0') ? 1 : 0;
                    int cost_match = (s2[i] == '1') ? 1 : 0;
                    int total_transition = cost_i + cost_next + 1 + cost_match;
                    next_dp1 = min(next_dp1, dp0 + total_transition);
                }
            }
            
            // Process from j = 1
            if (dp1 < 1e9) {
                char curr_char = '0';
                // Transition to k = 0
                int cost = 1e9;
                if (curr_char == s2[i]) {
                    cost = 0;
                } else if (curr_char == '0' && s2[i] == '1') {
                    cost = 1;
                }
                if (cost < 1e9) {
                    next_dp0 = min(next_dp0, dp1 + cost);
                }
                
                // Transition to k = 1
                if (i < n - 1) {
                    int cost_i = (curr_char == '0') ? 1 : 0;
                    int cost_next = (s1[i + 1] == '0') ? 1 : 0;
                    int cost_match = (s2[i] == '1') ? 1 : 0;
                    int total_transition = cost_i + cost_next + 1 + cost_match;
                    next_dp1 = min(next_dp1, dp1 + total_transition);
                }
            }
            
            dp0 = next_dp0;
            dp1 = next_dp1;
        }
        
        int ans = dp0;
        return (ans >= 1e9) ? -1 : ans;
    }
};

void run_test(string s1, string s2, int expected) {
    Solution solver;
    int ans = solver.minOperations(s1, s2);
    cout << "s1: \"" << s1 << "\", s2: \"" << s2 << "\" -> got: " << ans << ", expected: " << expected;
    if (ans == expected) {
        cout << " [PASSED]" << endl;
    } else {
        cout << " [FAILED]" << endl;
        exit(1);
    }
}

int main() {
    run_test("11", "00", 1);
    run_test("01", "10", 3);
    run_test("1", "0", -1);
    run_test("10", "01", 3);
    run_test("100", "001", 3);
    run_test("101", "000", 4);
    run_test("1001", "0000", 4);
    run_test("10001", "00000", 4);
    run_test("110", "011", 3);
    run_test("1010", "0101", 6);
    run_test("0000", "1111", 4);
    run_test("1111", "0000", 2);
    run_test("10101", "00000", 6);
    cout << "All tests passed successfully!" << endl;
    return 0;
}
