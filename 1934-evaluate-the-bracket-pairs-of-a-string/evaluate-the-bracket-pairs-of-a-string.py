class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:

        mapping = {key: value for key, value in knowledge}
        
        result = []
        i = 0
        n = len(s)
        
        while i < n:
            if s[i] == '(':

                j = i + 1
                while j < n and s[j] != ')':
                    j += 1
                

                key = s[i + 1:j]
                
            
                result.append(mapping.get(key, '?'))
                

                i = j + 1
            else:
                result.append(s[i])
                i += 1
                
        return "".join(result)