def solve(n, a, b, c):
    if a == 0:
        q = b // c
        f = n * q
        g = n * q**2
        h = (n * (n - 1) // 2) * q
        return f, g, h
    
    if a >= c or b >= c:
        qa = a // c
        qb = b // c
        a0 = a % c
        b0 = b % c
        rf, rg, rh = solve(n, a0, b0, c)
        
        sum_x2 = (n - 1) * n * (2 * n - 1) // 6
        sum_x = n * (n - 1) // 2
        
        f = qa * sum_x + qb * n + rf
        g = qa**2 * sum_x2 + 2 * qa * qb * sum_x + qb**2 * n + rg + 2 * qa * rh + 2 * qb * rf
        h = qa * sum_x2 + qb * sum_x + rh
        return f, g, h

    y_max = (a * n + b) // c
    if y_max == 0:
        return 0, 0, 0
    
    rf, rg, rh = solve(y_max, c, c - b - 1, a)
    
    f = (n - 1) * y_max - rf
    g = (n - 1) * y_max**2 - 2 * rh - rf
    h = n * (n - 1) // 2 * y_max - (rg + rf) // 2
    return f, g, h

def F0_fast(K, C, M, R):
    # F0(R) = K + f(K, C, 0, M) - f(K, C, M - R - 1, M)
    f1, _, _ = solve(K, C, 0, M)
    f2, _, _ = solve(K, C, M - R - 1, M)
    return K + f1 - f2

def F1_fast(K, C, M, R):
    # F1(R) = C * ( K*(K-1)/2 + h(K, C, 0, M) - h(K, C, M-R-1, M) ) - M * S2
    _, _, h1 = solve(K, C, 0, M)
    _, _, h2 = solve(K, C, M - R - 1, M)
    
    sum_k = K * (K - 1) // 2 + h1 - h2
    
    # S2 = h(Q1 + 1, M, R, C) - h(Q + 1, M, C-1, C) + Q*(Q+1)/2 + (K-1) * (Q*(Q+1) - Q1*(Q1+1))//2
    Q = (C * K - 1) // M
    Q1 = (C * K - 1 - R) // M
    
    if Q1 < 0:
        h_q1 = 0
        sum_q1 = 0
    else:
        _, _, h_q1 = solve(Q1 + 1, M, R, C)
        sum_q1 = Q1 * (Q1 + 1) // 2
        
    _, _, h_q = solve(Q + 1, M, C - 1, C)
    sum_q = Q * (Q + 1) // 2
    
    S2 = h_q1 - h_q + sum_q + (K - 1) * (sum_q - sum_q1)
    
    return C * sum_k - M * S2

# Naive versions for verification
def naive(K, C, M, R):
    f0 = 0
    f1 = 0
    for k in range(K):
        val = (C * k) % M
        if val <= R:
            f0 += 1
            f1 += val
    return f0, f1

# Test
K, C, M, R = 15, 3, 7, 4
print("Naive F0:", naive(K, C, M, R)[0], "Fast F0:", F0_fast(K, C, M, R))
print("Naive F1:", naive(K, C, M, R)[1], "Fast F1:", F1_fast(K, C, M, R))
