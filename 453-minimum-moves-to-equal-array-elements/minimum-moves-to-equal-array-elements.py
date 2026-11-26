class Solution:
    def minMoves(self, nums: List[int]) -> int:
        n=min(nums)
        moves=0
        for i in nums:
            moves+=i-n
        return moves    
        