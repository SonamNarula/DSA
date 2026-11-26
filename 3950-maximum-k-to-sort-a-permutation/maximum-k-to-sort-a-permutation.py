class Solution:
    def sortPermutation(self, A):
        return (lambda a: reduce(and_, a) if a else 0)((lambda s: [v for i, v in enumerate(A) if v != s[i]])(sorted(A)))