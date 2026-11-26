class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        N = len(nums)

        def canRotate(collected):
            n, drop = len(collected), 0
            for i in range(n):
                if collected[i] > collected[(i+1) % n]:
                    drop += 1
            return drop <= 1
        
        total = 0
        for k in range(1, N+1):
            if N % k != 0:
                continue

            preMax, redFlag, curSubarr = -inf, 0, []
            for i in range(N):
                curSubarr.append(nums[i])
                if len(curSubarr) == k:
                    if preMax > min(curSubarr) or not canRotate(curSubarr):
                        redFlag = 1
                        break
                    preMax = max(curSubarr)
                    curSubarr = []
     
            if not redFlag:
                total += k

        return total