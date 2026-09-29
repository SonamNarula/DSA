from functools import cache

class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])
      
        if (m + n - 1) % 2 != 0:
            return False
        

        if grid[0][0] == ')' or grid[m - 1][n - 1] == '(':
            return False

        @cache
        def dfs(r: int, c: int, balance: int) -> bool:

            balance += 1 if grid[r][c] == '(' else -1
            

            if balance < 0:
                return False
            
          
            if r == m - 1 and c == n - 1:
                return balance == 0
            

            if r + 1 < m and dfs(r + 1, c, balance):
                return True
                

            if c + 1 < n and dfs(r, c + 1, balance):
                return True
                
            return False

        return dfs(0, 0, 0)