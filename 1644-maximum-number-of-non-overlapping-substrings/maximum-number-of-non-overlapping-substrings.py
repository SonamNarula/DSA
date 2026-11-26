class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        # Step 1: Track the first and last occurrence of each character
        first = {}
        last = {}
        for i, ch in enumerate(s):
            if ch not in first:
                first[ch] = i
            last[ch] = i

        valid_intervals = []

        # Step 2: Expand intervals for each character's starting position
        for ch in set(s):
            left = first[ch]
            right = last[ch]
            is_valid = True
            
            i = left
            while i <= right:
                # If a character inside starts before 'left', this 'left' cannot be a valid start
                if first[s[i]] < left:
                    is_valid = False
                    break
                right = max(right, last[s[i]])
                i += 1
            
            if is_valid:
                valid_intervals.append((right, left))

        # Step 3: Sort by end index to apply greedy choice
        valid_intervals.sort()

        result = []
        last_end = -1

        for right, left in valid_intervals:
            if left > last_end:
                result.append(s[left:right + 1])
                last_end = right

        return result