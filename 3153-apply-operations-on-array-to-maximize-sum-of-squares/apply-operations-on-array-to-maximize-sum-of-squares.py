class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        bit_counts = [0] * 32
        

        for x in nums:
            for i in range(32):
                if (x >> i) & 1:
                    bit_counts[i] += 1
                    

        new_nums = [0] * k
        for i in range(32):
            if bit_counts[i] > 0:
                for j in range(min(k, bit_counts[i])):
                    new_nums[j] |= (1 << i)
                    

        ans = 0
        for x in new_nums:
            ans = (ans + x * x) % MOD
            
        return ans