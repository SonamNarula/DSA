class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        n = len(arr)
        # best[i] store karega index i tak milne wale sabse chhote subarray ki length
        best = [float('inf')] * n
        
        left = 0
        current_sum = 0
        ans = float('inf')
        min_len = float('inf')
        
        for right in range(n):
            current_sum += arr[right]
            
            # Window sum ko target ke barabar ya kam karne ke liye left pointer aage badhayein
            while current_sum > target:
                current_sum -= arr[left]
                left += 1
                
            # Valid subarray milne par
            if current_sum == target:
                length = right - left + 1
                
                # Agar left - 1 index tak koi pichhla valid subarray exist karta hai
                if left > 0 and best[left - 1] != float('inf'):
                    ans = min(ans, length + best[left - 1])
                
                min_len = min(min_len, length)
            
            # Current index right tak ka minimum length update karein
            best[right] = min_len
            
        return ans if ans != float('inf') else -1