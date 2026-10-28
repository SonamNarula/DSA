class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        n = len(grid[0])
        dp = [set([0])]+[set() for _ in range(n-1)]
        for row in grid:
            dp_cur = [set()]
            for i in range(n):
                dp_cur.append(set([x^row[i] for x in dp[i]|dp_cur[-1]]))
            dp = dp_cur[1:]
        return min(dp[-1])