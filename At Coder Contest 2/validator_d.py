import random
import subprocess
import sys

def digit_sum(n):
    return sum(int(c) for c in str(n))

def brute_solve(n, a, b):
    # Returns a list of min digit sums for k = 1..n
    # Since we want to solve for each k, we can do it recursively or iteratively
    # We can just keep a set of all possible values of X_i at each step
    possible = {0}
    ans = []
    for i in range(n):
        next_possible = set()
        for x in possible:
            next_possible.add(10 * x + a[i])
            next_possible.add(10 * x + b[i])
        ans.append(min(digit_sum(x) for x in next_possible))
        possible = next_possible
    return ans

def run_cpp(n, a, b):
    # Runs the C++ executable with input
    input_str = f"{n}\n" + " ".join(map(str, a)) + "\n" + " ".join(map(str, b)) + "\n"
    res = subprocess.run(["./d"], input=input_str, text=True, capture_output=True)
    if res.returncode != 0:
        print(f"C++ run failed with error: {res.stderr}")
        sys.exit(1)
    return list(map(int, res.stdout.strip().split()))

# Compile C++ first
subprocess.run(["g++", "-O3", "-Wall", "-Wextra", "-std=c++17", "D - Shift and Add.cpp", "-o", "d"])

random.seed(42)
for tc in range(100):
    n = random.randint(1, 12)
    a = [random.randint(1, 10**9 - 1) for _ in range(n)]
    b = [random.randint(1, 10**9 - 1) for _ in range(n)]
    
    brute = brute_solve(n, a, b)
    cpp = run_cpp(n, a, b)
    
    if brute != cpp:
        print(f"Failed at test case {tc}")
        print("A:", a)
        print("B:", b)
        print("Brute:", brute)
        print("C++:", cpp)
        sys.exit(1)

print("All 100 random validation tests passed successfully!")
