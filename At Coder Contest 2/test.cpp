#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int digits_A[5][10];
int digits_B[5][10];
int N = 2;

int get_digit(int idx, int pos, int choice) {
    if (idx <= 0 || idx > N) return 0;
    if (choice == 2) return 0;
    return (choice == 0) ? digits_A[idx][pos] : digits_B[idx][pos];
}

int main() {
    digits_A[1][0] = 3; digits_A[1][1] = 2; digits_A[1][2] = 1;
    digits_B[1][0] = 6; digits_B[1][1] = 5; digits_B[1][2] = 4;
    
    digits_A[2][0] = 4; digits_A[2][1] = 4; digits_A[2][2] = 4;
    digits_B[2][0] = 2; digits_B[2][1] = 2; digits_B[2][2] = 2;
    
    vector<vector<int>> dp(6561, vector<int>(10, INF));
    for (int mask = 0; mask < 6561; mask++) {
        dp[mask][0] = 0;
    }
    
    for (int i = -7; i <= 2; i++) {
        vector<vector<int>> next_dp(6561, vector<int>(10, INF));
        for (int mask = 0; mask < 6561; mask++) {
            // Check if mask is reachable
            // At step i, digit j-1 of mask must be 2 if i + j > N
            bool ok = true;
            int temp = mask;
            for (int j = 1; j <= 8; j++) {
                int digit = temp % 3;
                temp /= 3;
                if (i + j > N && digit != 2) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            
            // Compute sum of digits for C_{i+1} ... C_{i+8}
            int sum_digits_mask = 0;
            temp = mask;
            for (int j = 1; j <= 8; j++) {
                int digit = temp % 3;
                temp /= 3;
                sum_digits_mask += get_digit(i + j, j, digit);
            }
            
            for (int carry = 0; carry < 10; carry++) {
                int max_choice = (i >= 1) ? 2 : 1;
                for (int choice = 0; choice < max_choice; choice++) {
                    int sum = get_digit(i, 0, choice) + sum_digits_mask + carry;
                    int digit = sum % 10;
                    int new_carry = sum / 10;
                    int new_mask = (mask % 2187) * 3 + choice;
                    
                    if (new_carry < 10 && dp[new_mask][new_carry] != INF) {
                        next_dp[mask][carry] = min(next_dp[mask][carry], dp[new_mask][new_carry] + digit);
                    }
                }
            }
        }
        dp = next_dp;
        cout << "i = " << i << ", dp[6560][0] = " << dp[6560][0] << endl;
    }
    return 0;
}
