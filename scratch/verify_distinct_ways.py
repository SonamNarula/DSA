def solve(word1, word2, target):
    N1 = len(word1)
    N2 = len(word2)
    L = len(target)
    MOD = 10**9 + 7
    
    # dp[i][j][mask]
    dp = [[[0]*4 for _ in range(N2 + 1)] for _ in range(N1 + 1)]
    dp[0][0][0] = 1
    
    for k in range(L):
        char = target[k]
        next_dp = [[[0]*4 for _ in range(N2 + 1)] for _ in range(N1 + 1)]
        
        # S1[i][j][mask] = sum_{x < i} dp[x][j][mask]
        S1 = [[[0]*4 for _ in range(N2 + 1)] for _ in range(N1 + 2)]
        for j in range(N2 + 1):
            for mask in range(4):
                running = 0
                for i in range(N1 + 1):
                    S1[i][j][mask] = running
                    running = (running + dp[i][j][mask]) % MOD
        
        # S2[i][j][mask] = sum_{y < j} dp[i][y][mask]
        S2 = [[[0]*4 for _ in range(N2 + 2)] for _ in range(N1 + 1)]
        for i in range(N1 + 1):
            for mask in range(4):
                running = 0
                for j in range(N2 + 1):
                    S2[i][j][mask] = running
                    running = (running + dp[i][j][mask]) % MOD
                    
        # Word1 match
        for i_prime in range(1, N1 + 1):
            if word1[i_prime - 1] == char:
                for j in range(N2 + 1):
                    for mask in range(4):
                        val = S1[i_prime][j][mask]
                        next_dp[i_prime][j][mask | 1] = (next_dp[i_prime][j][mask | 1] + val) % MOD
                        
        # Word2 match
        for j_prime in range(1, N2 + 1):
            if word2[j_prime - 1] == char:
                for i in range(N1 + 1):
                    for mask in range(4):
                        val = S2[i][j_prime][mask]
                        next_dp[i][j_prime][mask | 2] = (next_dp[i][j_prime][mask | 2] + val) % MOD
                        
        dp = next_dp
        
    ans = 0
    for i in range(N1 + 1):
        for j in range(N2 + 1):
            ans = (ans + dp[i][j][3]) % MOD
    return ans

# Test examples
print("Ex 1:", solve("abc", "bac", "abc")) # Expected: 5
print("Ex 2:", solve("cd", "cd", "ccd"))   # Expected: 4
print("Ex 3:", solve("xy", "xy", "xyxy")) # Expected: 2
print("Ex 4:", solve("ab", "cde", "ace")) # Expected: 1
