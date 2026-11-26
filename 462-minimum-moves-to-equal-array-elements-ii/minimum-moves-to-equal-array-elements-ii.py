class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        l=len(nums)
        nums.sort()
        m = l//2
        return (sum(nums[m+1:])-sum(nums[:m])) if l%2==1 else (sum(nums[m:])-sum(nums[:m]))
        
        