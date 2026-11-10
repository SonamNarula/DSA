class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        @cache
        def stair_no(x):
            if x<0: return float('inf')
            if x == 0: return 0
            return min(
                stair_no(x-1) + costs[x-1] + 1,
                stair_no(x-2) + costs[x-1] + 4,
                stair_no(x-3) + costs[x-1] + 9,
            )

        return stair_no(n)
        