class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        # Knowledge list ko dictionary mein convert karein
        mapping = {key: value for key, value in knowledge}
        
        result = []
        i = 0
        n = len(s)
        
        while i < n:
            if s[i] == '(':
                # Key ka start position khojein
                j = i + 1
                while j < n and s[j] != ')':
                    j += 1
                
                # '(' aur ')' ke beech ki key nikalein
                key = s[i + 1:j]
                
                # Key agar dictionary mein hai toh uski value add karein, nahi toh '?'
                result.append(mapping.get(key, '?'))
                
                # Index ko ')' ke aage shift karein
                i = j + 1
            else:
                result.append(s[i])
                i += 1
                
        return "".join(result)