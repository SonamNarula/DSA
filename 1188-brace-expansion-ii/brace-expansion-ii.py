class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        # Stack to store state before entering a '{'
        stack = []
        # Current group of words being built (union level)
        res = set()
        # Current concatenated block of sets
        cur = [{""}]
        
        for c in expression:
            if c.isalpha():
                # Single letter: multiply with the last set in cur
                cur[-1] = {s + c for s in cur[-1]}
            elif c == '{':
                # Push current state onto stack and start fresh inside braces
                stack.append((res, cur))
                res, cur = set(), [{""}]
            elif c == '}':
                # Union all accumulated sets in cur into res
                for s in cur:
                    res.update(s)
                # Pop state from stack
                prev_res, prev_cur = stack.pop()
                # Multiply the popped cur's last element with the evaluated res of current braces
                prev_cur[-1] = {a + b for a in prev_cur[-1] for b in res}
                res, cur = prev_res, prev_cur
            elif c == ',':
                # Comma means we take union of cur sets into res, then reset cur
                for s in cur:
                    res.update(s)
                cur = [{""}]
        
        # Combine remaining sets in cur into res
        for s in cur:
            res.update(s)
            
        # Return unique words sorted lexicographically
        return sorted(list(res))