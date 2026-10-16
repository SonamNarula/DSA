class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        tree = [0] * (4 * n)
        lazy = [0] * (4 * n)
        sum_val = [0] * (4 * n)
        
        def push(node, l, r):
            if lazy[node] != 0:
                val = lazy[node]
                mid = (l + r) // 2
                
                lazy[2 * node] = (lazy[2 * node] + val) % MOD
                sum_val[2 * node] = (sum_val[2 * node] + val * (mid - l + 1)) % MOD
                tree[2 * node] = (tree[2 * node] + 2 * val * sum_val[2 * node] - 2 * val * val * (mid - l + 1) + val * val * (mid - l + 1)) % MOD
                
                lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % MOD
                sum_val[2 * node + 1] = (sum_val[2 * node + 1] + val * (r - mid)) % MOD
                tree[2 * node + 1] = (tree[2 * node + 1] + 2 * val * sum_val[2 * node + 1] - 2 * val * val * (r - mid) + val * val * (r - mid)) % MOD
                
                lazy[node] = 0

        def update(node, l, r, ql, qr, val):
            if ql > r or qr < l:
                return
            if ql <= l and r <= qr:
                lazy[node] = (lazy[node] + val) % MOD
                tree[node] = (tree[node] + 2 * val * sum_val[node] + val * val * (r - l + 1)) % MOD
                sum_val[node] = (sum_val[node] + val * (r - l + 1)) % MOD
                return
            
            push(node, l, r)
            mid = (l + r) // 2
            update(2 * node, l, mid, ql, qr, val)
            update(2 * node + 1, mid + 1, r, ql, qr, val)
            
            tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD
            sum_val[node] = (sum_val[2 * node] + sum_val[2 * node + 1]) % MOD

        last = {}
        ans = 0
        
        for j in range(n):
            i = last.get(nums[j], -1) + 1
            last[nums[j]] = j
            
            update(1, 0, n - 1, i, j, 1)
            ans = (ans + tree[1]) % MOD
            
        return ans