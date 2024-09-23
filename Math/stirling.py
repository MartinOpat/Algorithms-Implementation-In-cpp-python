from functools import lru_cache
import math
from sys import setrecursionlimit

setrecursionlimit(10**9)

@lru_cache(maxsize=None)
def fact(n):
    if n == 0 or n == 1:
        return 1
    return n * fact(n-1)


# @lru_cache(maxsize=None)
def S_naive(n):
    return math.sqrt(2*math.pi*n) * math.pow(n/math.e, n)

def err(n):
    ans = 1
    for i in range(n):
        if float("inf") > ans > 1.1:
            print(ans)
        if ans >= float("inf"):
            print(i, n)
            exit(1)
        ans *= (n-i) / n * math.e 
        ans *= math.e - i / n * math.e
    return ans / math.sqrt(2*math.pi*n)


def err2(n):
    if n == 1:
        return 0.5 *math.log(1)
    ans = 0.5 *math.log(1) + 0.5 * math.log(n)
    for i in range(2, n):
        ans += math.log(i)
    return ans

def log_factorial(n):
    # Using summation of logs to avoid computing the large factorial directly
    return sum(math.log(i) for i in range(1, n + 1))

def log_stirling_approximation(n):
    # Logarithmic version of Stirling's approximation
    return (0.5 * math.log(2 * math.pi * n)) + n * (math.log(n) - 1)

def compute_approximation_ratio_log(n):
    if n == 0:
        return 1
    # Compute the logarithmic difference between log(n!) and log(S(n))
    log_exact_factorial = log_factorial(n)
    log_stirling = log_stirling_approximation(n)
    
    # Return exp of the difference to get the ratio
    return math.exp(log_exact_factorial - log_stirling)

        

n = int(input())
while n != 0:
    # print(f"{fact(n) / S_naive(n):.9f}")
    # print(f"{err(n):.9f}")
    print(compute_approximation_ratio_log(n))
    n = int(input())