from collections import deque
from typing import List

class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        if not grid or not grid[0]:
            return 0

        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]
        ans = 0

        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        for i in range(m):
            for j in range(n):
                if grid[i][j] <= 0 or visited[i][j]:
                    continue

                q = deque()
                q.append((i, j))
                visited[i][j] = True
                total_mod = grid[i][j] % k

                while q:
                    x, y = q.popleft()
                    for dx, dy in directions:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny] and grid[nx][ny] > 0:
                            visited[nx][ny] = True
                            q.append((nx, ny))
                            total_mod = (total_mod + grid[nx][ny]) % k

                if total_mod == 0:
                    ans += 1

        return ans
