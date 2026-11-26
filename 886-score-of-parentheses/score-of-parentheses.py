class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack = [0]  # Tracks scores at each nesting level

        for char in s:
            if char == '(':
                stack.append(0)
            else:
                last_score = stack.pop()
                # If () -> score is 1; if (A) -> score is 2 * A
                current_score = max(2 * last_score, 1)
                stack[-1] += current_score

        return stack[0]