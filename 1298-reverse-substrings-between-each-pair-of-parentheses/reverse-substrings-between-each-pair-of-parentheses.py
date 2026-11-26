class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        pair = {}
        stack = []
        
        # Precompute matching parenthesis indices
        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)
            elif char == ')':
                j = stack.pop()
                pair[i] = j
                pair[j] = i
                
        # Traverse string in alternating directions
        result = []
        curr, direction = 0, 1
        
        while curr < n:
            if s[curr] in '()':
                curr = pair[curr]
                direction = -direction
            else:
                result.append(s[curr])
            curr += direction
            
        return "".join(result)