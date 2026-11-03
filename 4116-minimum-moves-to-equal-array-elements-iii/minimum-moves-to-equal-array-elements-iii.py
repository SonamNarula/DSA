class Solution:
    def minMoves(self, nums: List[int]) -> int:
        moves = 0
        maxnum = max(nums)
        for i in range(len(nums)):
            moves += (maxnum - nums[i])
        return moves