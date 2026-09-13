from collections import defaultdict
from typing import List

class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        
        # 1. Dono images mein '1' wale saare coordinates find karein
        list1 = [(r, c) for r in range(n) for c in range(n) if img1[r][c] == 1]
        list2 = [(r, c) for r in range(n) for c in range(n) if img2[r][c] == 1]
        
        # 2. Har pair ke beech ka shift vector (dr, dc) calculate karke count karein
        count = defaultdict(int)
        max_overlap = 0
        
        for r1, c1 in list1:
            for r2, c2 in list2:
                # Delta (shift) from img1 to img2
                dr = r2 - r1
                dc = c2 - c1
                
                count[(dr, dc)] += 1
                max_overlap = max(max_overlap, count[(dr, dc)])
                
        return max_overlap