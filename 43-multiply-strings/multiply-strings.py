class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        # Result array to hold digits (max possible length is len(num1) + len(num2))
        res = [0] * (len(num1) + len(num2))

        # Reverse both strings to multiply from right to left (ones digit first)
        num1, num2 = num1[::-1], num2[::-1]

        for i in range(len(num1)):
            for j in range(len(num2)):
                digit1 = ord(num1[i]) - ord('0')
                digit2 = ord(num2[j]) - ord('0')

                # Position where the product digit belongs
                pos = i + j
                
                # Add product to the current position
                res[pos] += digit1 * digit2
                
                # Handle carry over to the next position
                res[pos + 1] += res[pos] // 10
                res[pos] %= 10

        # Remove leading zeros from the reversed result array
        while len(res) > 1 and res[-1] == 0:
            res.pop()

        # Convert back to string and reverse
        return "".join(map(str, res[::-1]))