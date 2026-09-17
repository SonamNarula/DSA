class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        if n <= 1:
            return 0
            
        dp = [i for i in range(n)]
        
        for center in range(n):
            # Odd-length palindromes (single character center)
            left, right = center, center
            while left >= 0 and right < n and s[left] == s[right]:
                new_cuts = 0 if left == 0 else dp[left - 1] + 1
                dp[right] = min(dp[right], new_cuts)
                left -= 1
                right += 1
                
            # Even-length palindromes (two character center)
            left, right = center, center + 1
            while left >= 0 and right < n and s[left] == s[right]:
                new_cuts = 0 if left == 0 else dp[left - 1] + 1
                dp[right] = min(dp[right], new_cuts)
                left -= 1
                right += 1
                
        return dp[-1]