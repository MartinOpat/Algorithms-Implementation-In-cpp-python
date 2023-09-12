
n, m = map(int, input().split())


# Using Fermat's little theorem to compute nCk mod p
# Note: p must be prime and k < p
def fermat_binom(n, k, p):
    if k > n:
        return 0

    # calculate numerator
    num = 1
    for i in range(n-k+1, n+1):
        num *= i % p
    num %= p

    # calculate denominator
    denom = 1
    for i in range(1,k+1):
        denom *= i % p
    denom %= p

    # numerator * denominator^(p-2) (mod p)
    return (num * pow(denom, p-2, p)) % p


print(fermat_binom(m, n, 10**9+7) if m > n else fermat_binom(n-1, m-1, 10**9+7))
