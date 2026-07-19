import collections
import sys

def get_neighbors(s):
    n = len(s)
    neighbors = []
    # Op 1: 0 -> 1
    for i in range(n):
        if s[i] == '0':
            t = list(s)
            t[i] = '1'
            neighbors.append(("".join(t), 1))
    # Op 2: 11 -> 00
    for i in range(n - 1):
        if s[i] == '1' and s[i+1] == '1':
            t = list(s)
            t[i] = '0'
            t[i+1] = '0'
            neighbors.append(("".join(t), 1))
    return neighbors

def solve(s1, s2):
    if s1 == s2:
        return 0
    # BFS
    queue = collections.deque([(s1, 0)])
    visited = {s1: 0}
    while queue:
        curr, cost = queue.popleft()
        if curr == s2:
            return cost
        for nxt, step in get_neighbors(curr):
            nxt_cost = cost + step
            if nxt not in visited or nxt_cost < visited[nxt]:
                visited[nxt] = nxt_cost
                queue.append((nxt, nxt_cost))
    return -1

if __name__ == "__main__":
    if len(sys.argv) < 3:
        # Run some test cases
        tests = [
            ("11", "00"),
            ("01", "10"),
            ("1", "0"),
            ("10", "01"),
            ("100", "001"),
            ("101", "000"),
            ("1001", "0000"),
            ("10001", "00000"),
            ("100001", "000000"),
            ("110", "011"),
            ("1010", "0101"),
            ("0000", "1111"),
            ("1111", "0000"),
            ("10101", "00000"),
        ]
        for s1, s2 in tests:
            print(f"'{s1}' -> '{s2}': {solve(s1, s2)}")
    else:
        print(solve(sys.argv[1], sys.argv[2]))
