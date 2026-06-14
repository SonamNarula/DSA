import sys

# Brute force solver for N=2 or N=3
def brute_solve(n, a, h, w):
    # We want to find a set of white cells W (subsets of cells)
    # such that Alice wins from (h, w) under W.
    # To do this, we can define the game outcome for each state.
    # Since the game has 10^10 turns, the outcome from each state is stable.
    # A state is (turn_player, r, c), where turn_player in {'Alice', 'Bob'}.
    # Alice wins from (Alice, r, c) if there exists a horizontal move to (Bob, r, c') such that Alice wins.
    # Bob wins from (Bob, r, c) if there exists a move to (Alice, r', c') such that Bob wins.
    # If Bob cannot win, Alice wins.
    # So Alice wins from (Bob, r, c) iff for all moves to (Alice, r', c'), Alice wins.
    # The game starts at (Alice, h, w).
    # We want to find the minimum sum of a[r][c] for (r, c) in W
    # such that Alice wins from (Alice, h, w).
    
    # We can iterate over all subsets W of cells.
    # Since N <= 3, the number of cells is at most 9.
    # The number of subsets W is 2^9 = 512.
    # For a fixed W, we can determine the winning states by solving the game.
    # Since it's a finite game with no cycles if we only care about winning/losing:
    # Actually, we can just compute the winning states using a fixed-point iteration.
    # Let win[player][r][c] be 1 if Alice wins, 0 if Bob wins.
    # Initially, for Bob's turn, Alice wins if the cell is in W. But wait!
    # Bob moves, then Alice moves, ..., until the end.
    # Since the last move is by Bob, the game ends on Bob's turn.
    # So at the end of Bob's turn, Alice wins if the cell is in W.
    # Since the number of steps is even, we can compute the winning states:
    # Let's run a fixed-point iteration:
    # win_A[r][c] = Alice wins on Alice's turn at (r, c).
    # win_B[r][c] = Alice wins on Bob's turn at (r, c).
    # Transitions:
    # win_A[r][c] = 1 if there exists c' in {c-1, c+1} within bounds such that win_B[r][c'] == 1.
    # win_B[r][c] = 1 if (r, c) in W AND for all neighbors (r', c') of (r, c), win_A[r'][c'] == 1.
    # Let's run this iteration until convergence.
    
    cells = []
    for r in range(1, n+1):
        for c in range(1, n+1):
            cells.append((r, c))
            
    min_cost = float('inf')
    
    for mask in range(1 << len(cells)):
        W = set()
        cost = 0
        for idx, cell in enumerate(cells):
            if (mask >> idx) & 1:
                W.add(cell)
                cost += a[cell[0]-1][cell[1]-1]
                
        if cost >= min_cost:
            continue
            
        # Fixed point iteration
        win_A = [[0]*(n+1) for _ in range(n+1)]
        # Initially, after Bob's last turn (0 steps remaining), Alice wins if the piece is in W
        for r, c in W:
            win_A[r][c] = 1
            
        win_B = [[0]*(n+1) for _ in range(n+1)]
        
        # Run 100 full rounds (each round is Bob's turn then Alice's turn)
        for _ in range(100):
            # Update win_B: Alice wins on Bob's turn if all Bob's moves lead to a state where Alice wins (win_A)
            next_win_B = [[0]*(n+1) for _ in range(n+1)]
            for r in range(1, n+1):
                for c in range(1, n+1):
                    all_win = True
                    for dr, dc in [(-1,0), (1,0), (0,-1), (0,1)]:
                        nr, nc = r + dr, c + dc
                        if 1 <= nr <= n and 1 <= nc <= n:
                            if win_A[nr][nc] == 0:
                                all_win = False
                                break
                    next_win_B[r][c] = 1 if all_win else 0
            
            # Update win_A: Alice wins on Alice's turn if there exists a horizontal move to a win_B state
            next_win_A = [[0]*(n+1) for _ in range(n+1)]
            for r in range(1, n+1):
                for c in range(1, n+1):
                    can_win = False
                    for dc in [-1, 1]:
                        nc = c + dc
                        if 1 <= nc <= n:
                            if next_win_B[r][nc] == 1:
                                can_win = True
                                break
                    next_win_A[r][c] = 1 if can_win else 0
            
            if win_A == next_win_A and win_B == next_win_B:
                break
            win_A = next_win_A
            win_B = next_win_B
                
        if win_A[h][w] == 1:
            min_cost = cost
            
    return min_cost

# DP Solver
def dp_solve(n, a, h, w):
    cost = [[0]*(n+1) for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(1, n+1):
            left = a[i-1][j-2] if j-1 >= 1 else 0
            right = a[i-1][j] if j+1 <= n else 0
            cost[i][j] = left + right
            
    dp_down = [[float('inf')]*(n+2) for _ in range(n+2)]
    for j in range(1, n+1):
        dp_down[1][j] = cost[1][j]
    for i in range(2, n+1):
        for j in range(1, n+1):
            prev_min = float('inf')
            if j - 1 >= 1: prev_min = min(prev_min, dp_down[i - 1][j - 1])
            if j + 1 <= n: prev_min = min(prev_min, dp_down[i - 1][j + 1])
            if prev_min != float('inf'):
                dp_down[i][j] = cost[i][j] + prev_min
                
    dp_up = [[float('inf')]*(n+2) for _ in range(n+2)]
    for j in range(1, n+1):
        dp_up[n][j] = cost[n][j]
    for i in range(n-1, 0, -1):
        for j in range(1, n+1):
            next_min = float('inf')
            if j - 1 >= 1: next_min = min(next_min, dp_up[i + 1][j - 1])
            if j + 1 <= n: next_min = min(next_min, dp_up[i + 1][j + 1])
            if next_min != float('inf'):
                dp_up[i][j] = cost[i][j] + next_min
                
    min_cost_val = [[float('inf')]*(n+1) for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(1, n+1):
            if dp_down[i][j] != float('inf') and dp_up[i][j] != float('inf'):
                min_cost_val[i][j] = dp_down[i][j] + dp_up[i][j] - cost[i][j]
                
    ans = float('inf')
    if w - 1 >= 1: ans = min(ans, min_cost_val[h][w - 1])
    if w + 1 <= n: ans = min(ans, min_cost_val[h][w + 1])
    return ans

# Generate random tests
import random
random.seed(42)
for tc in range(100):
    n = random.choice([2, 3])
    a = [[random.randint(0, 10) for _ in range(n)] for _ in range(n)]
    for h in range(1, n+1):
        for w in range(1, n+1):
            brute = brute_solve(n, a, h, w)
            dp = dp_solve(n, a, h, w)
            if brute != dp:
                print(f"Failed at tc={tc}, n={n}, h={h}, w={w}")
                print("Grid:")
                for row in a:
                    print(row)
                print(f"Brute: {brute}, DP: {dp}")
                sys.exit(1)
print("All 100 random tests passed!")
