class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        ans = 0
        last_end = -1
        
        # Har possible center par expand karke check karein
        for center in range(2 * n - 1):
            left = center // 2
            right = left + center % 2
            
            while left >= 0 and right < n and s[left] == s[right]:
                # Agar substring ki length >= k hai aur ye picchle selected palindrome ke baad start hota hai
                if right - left + 1 >= k:
                    if left > last_end:
                        ans += 1
                        last_end = right
                        break
                left -= 1
                right += 1
                
        return ans