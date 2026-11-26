class Fenwick:
    def __init__(self, arr):
        self.n = len(arr)
        self.bit = [0] * (self.n + 1)
        prev = 0
        for i, x in enumerate(arr):
            self._add(i, x ^ prev)
            prev = x

    def _add(self, i, x):
        i += 1
        while i <= self.n:
            self.bit[i] ^= x
            i += i & -i

    def update(self, l, r, x):
        self._add(l, x)
        if r + 1 < self.n:
            self._add(r + 1, x)

    def get(self, i):
        res = 0
        i += 1
        while i:
            res ^= self.bit[i]
            i -= i & -i
        return res

class Solution:
    def palindromePath(self, n, edges, s, queries):
        n = len(s)
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        L = n.bit_length() + 1
        p = [[i] * L for i in range(n)]
        tin = 0
        pos = [-1] * n
        ctr = [0] * n
        mask = 0
        d = [0] * n
        vals = [0] * n
        def dfs(u, pr, depth):
            nonlocal tin, mask
            d[u] = depth
            pos[u] = tin
            tin += 1
            ctr[u] = 1
            ux = ord(s[u]) - ord('a')
            mask ^= 1 << ux
            vals[pos[u]] = mask
            for v in g[u]:
                if v != pr:
                    p[v][0] = u
                    dfs(v, u, depth + 1)
                    ctr[u] += ctr[v]
            mask ^= 1 << ux
        dfs(0, -1, 0)
        for l in range(1, L):
            for i in range(n):
                p[i][l] = p[p[i][l - 1]][l - 1]
        def lca(u, v):
            if d[u] < d[v]:
                u, v = v, u
            diff = d[u] - d[v]
            for k in range(L):
                if diff & (1 << k):
                    u = p[u][k]
            if u == v:
                return u
            for k in range(L - 1, -1, -1):
                if p[u][k] != p[v][k]:
                    u = p[u][k]
                    v = p[v][k]
            return p[u][0]
        s = list(s)
        ds = Fenwick(vals)
        res = []
        for q in queries:
            q = q.split(" ")
            op = q[0]
            if op == "query":
                u = int(q[1])
                v = int(q[2])
                r = lca(u, v)
                x = ds.get(pos[u]) ^ ds.get(pos[v]) ^ (1 << (ord(s[r]) - ord('a')))
                res.append(x.bit_count() <= 1)
            if op == "update":
                u = int(q[1])
                old = ord(s[u]) - ord('a')
                s[u] = q[2]
                c = ord(s[u]) - ord('a')
                ds.update(pos[u], pos[u] + ctr[u] - 1, (1 << old) ^ (1 << c))
        return res