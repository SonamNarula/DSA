class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        rows = defaultdict(list)
        cols = defaultdict(list)
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    rows[i].append((i,j))
                    cols[j].append((i,j))
        ans = set()
        for i in rows:
            if len(rows[i]) > 1:
                ans |= set(rows[i])
        for i in cols:
            if len(cols[i]) > 1:
                ans |= set(cols[i])
        return len(ans)
                
            