class Solution:
    def palindromePairs(self, words: list[str]) -> list[list[int]]:
        lookup = {word: i for i, word in enumerate(words)}
        res = []
        
        for i, word in enumerate(words):
            k = len(word)
            for j in range(k + 1):
                prefix = word[:j]
                suffix = word[j:]
                
                # If prefix is palindrome, find reversed(suffix) + word
                if prefix == prefix[::-1]:
                    rev_suffix = suffix[::-1]
                    if rev_suffix in lookup and lookup[rev_suffix] != i:
                        res.append([lookup[rev_suffix], i])
                
                # If suffix is palindrome, find word + reversed(prefix)
                # j != k prevents duplicate counting when prefix == word
                if j != k and suffix == suffix[::-1]:
                    rev_prefix = prefix[::-1]
                    if rev_prefix in lookup and lookup[rev_prefix] != i:
                        res.append([i, lookup[rev_prefix]])
                        
        return res