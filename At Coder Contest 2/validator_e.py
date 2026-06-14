import random
import subprocess
import sys

MOD = 998244353

def solve_brute(n, m, a):
    # Direct formula computation
    cnt = [0] * (1 << m)
    for x in a:
        cnt[x] += 1
        
    f = [0] * (1 << m)
    # f(0)
    f[0] = sum(c // 2 for c in cnt) % MOD
    
    # f(X) for X > 0
    for X in range(1, 1 << m):
        val = 0
        for Y in range(1 << m):
            val += min(cnt[Y], cnt[Y ^ X])
        # since each pair {Y, Y ^ X} is counted twice, we divide by 2
        f[X] = (val // 2) % MOD
        
    # Output value
    ans = 0
    pow10 = 1
    for X in range(1 << m):
        ans = (ans + f[X] * pow10) % MOD
        pow10 = pow10 * 10 % MOD
    return ans

def run_cpp(n, m, a):
    input_str = f"{n} {m}\n" + " ".join(map(str, a)) + "\n"
    res = subprocess.run(["./e"], input=input_str, text=True, capture_output=True)
    if res.returncode != 0:
        print(f"C++ run failed with error: {res.stderr}")
        sys.exit(1)
    return int(res.stdout.strip())

# Compile C++ first
subprocess.run(["g++", "-O3", "-Wall", "-Wextra", "-std=c++17", "E - XOR Matching.cpp", "-o", "e"])

random.seed(42)
for tc in range(100):
    m = random.randint(1, 8)
    n = random.randint(2, 100)
    a = [random.randint(0, (1 << m) - 1) for _ in range(n)]
    
    brute = solve_brute(n, m, a)
    cpp = run_cpp(n, m, a)
    
    if brute != cpp:
        print(f"Failed at test case {tc}")
        print("M:", m, "N:", n)
        print("A:", a)
        print("Brute:", brute)
        print("C++:", cpp)
        sys.exit(1)

print("All 100 random validation tests for E passed successfully!")
