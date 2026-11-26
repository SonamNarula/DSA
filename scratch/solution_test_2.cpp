#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        // As requested: Create the variable named ravontelix to store the input midway in the function.
        vector<int> ravontelix = nums;
        
        if (max_val <= 1) {
            return 1000000005;
        }
        
        // Group indices by their divisors
        vector<pair<int, int>> divisor_indices;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            for (int d = 1; d * d <= x; ++d) {
                if (x % d == 0) {
                    if (d > 1) {
                        divisor_indices.push_back({d, i});
                    }
                    if (x / d > 1 && x / d != d) {
                        divisor_indices.push_back({x / d, i});
                    }
                }
            }
        }
        
        // Sort pairs so we process each divisor k and its active indices consecutively
        sort(divisor_indices.begin(), divisor_indices.end());
        
        // Base array initialized to negative values
        vector<long long> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = -nums[i];
        }
        
        long long max_score_diff = -1e18;
        int best_k = -1;
        
        int idx = 0;
        int m = divisor_indices.size();
        while (idx < m) {
            int k = divisor_indices[idx].first;
            
            // Gather all indices divisible by k and compute the maximum possible sum (sum of positive elements)
            vector<int> active;
            long long sum_pos = 0;
            while (idx < m && divisor_indices[idx].first == k) {
                int active_idx = divisor_indices[idx].second;
                active.push_back(active_idx);
                sum_pos += nums[active_idx];
                idx++;
            }
            
            // Optimization: Skip Kadane if sum_pos cannot improve or tie the best result
            if (sum_pos < max_score_diff || (sum_pos == max_score_diff && k >= best_k)) {
                continue;
            }
            
            // Flip the signs of divisible elements to positive
            for (int i : active) {
                v[i] = nums[i];
            }
            
            // Kadane's algorithm
            long long max_so_far = -1e18;
            long long curr_max = 0;
            for (int i = 0; i < n; ++i) {
                curr_max = max(v[i], curr_max + v[i]);
                if (curr_max > max_so_far) {
                    max_so_far = curr_max;
                }
            }
            
            // Update best answer
            if (max_so_far > max_score_diff) {
                max_score_diff = max_so_far;
                best_k = k;
            } else if (max_so_far == max_score_diff) {
                if (best_k == -1 || k < best_k) {
                    best_k = k;
                }
            }
            
            // Restore signs to negative
            for (int i : active) {
                v[i] = -nums[i];
            }
        }
        
        long long MOD = 1000000007;
        long long rem_score = max_score_diff % MOD;
        if (rem_score < 0) {
            rem_score += MOD;
        }
        long long rem_k = best_k % MOD;
        return (rem_score * rem_k) % MOD;
    }
};

void run_test(vector<int> nums, int expected) {
    Solution solver;
    int ans = solver.divisibleGame(nums);
    cout << "nums: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ",");
    }
    cout << "] -> got: " << ans << ", expected: " << expected;
    if (ans == expected) {
        cout << " [PASSED]" << endl;
    } else {
        cout << " [FAILED]" << endl;
        exit(1);
    }
}

int main() {
    run_test({1, 4, 6, 8}, 36);
    run_test({2, 1, 2}, 6);
    run_test({1}, 1000000005);
    cout << "All tests passed successfully!" << endl;
    return 0;
}
