import random
from bfs_solver import solve as bfs_solve

def dp_solve(s1, s2):
    n = len(s1)
    # dp[i][j] where j = 0 (not flipped) or 1 (flipped)
    INF = 10**9
    dp = [INF, INF]
    dp[0] = 0
    
    for i in range(n):
        next_dp = [INF, INF]
        # We can transition to k = 0 (no Op 2 on i, i+1)
        # or k = 1 (Op 2 on i, i+1) - only if i < n - 1
        
        for j in range(2):
            val_j = dp[j]
            if val_j >= INF:
                continue
            
            curr_char = '0' if j == 1 else s1[i]
            
            # Case k = 0
            if curr_char == s2[i]:
                cost = 0
            elif curr_char == '0' and s2[i] == '1':
                cost = 1
            else: # curr_char == '1' and s2[i] == '0'
                cost = INF
            
            if cost < INF:
                next_dp[0] = min(next_dp[0], val_j + cost)
                
            # Case k = 1 (only if i < n - 1)
            if i < n - 1:
                # To do Op 2 on i, i+1:
                # We need curr_char to be '1'. Cost to make it '1':
                cost_i = 1 if curr_char == '0' else 0
                # We need s1[i+1] to be '1'. Cost to make it '1':
                cost_next = 1 if s1[i+1] == '0' else 0
                # Op 2 cost is 1.
                # After Op 2, s1[i] becomes '0'. We need it to match s2[i].
                cost_match = 1 if s2[i] == '1' else 0
                
                total_transition = cost_i + cost_next + 1 + cost_match
                next_dp[1] = min(next_dp[1], val_j + total_transition)
                
        dp = next_dp
        
    ans = dp[0]
    return ans if ans < INF else -1

if __name__ == "__main__":
    # Test on some random cases
    random.seed(42)
    for _ in range(1000):
        length = random.randint(1, 8)
        s1 = "".join(random.choice(['0', '1']) for _ in range(length))
        s2 = "".join(random.choice(['0', '1']) for _ in range(length))
        ans_bfs = bfs_solve(s1, s2)
        ans_dp = dp_solve(s1, s2)
        if ans_bfs != ans_dp:
            print(f"Mismatch for s1='{s1}', s2='{s2}': BFS={ans_bfs}, DP={ans_dp}")
            exit(1)
    print("All 1000 random test cases passed successfully!")
