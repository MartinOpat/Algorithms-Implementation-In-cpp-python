

def to_int(c):
    return ord(c) - ord('0')


S = input()

lh, rh, re = 0, 0, 1
P, M = 31, 1000000007
l, r, ans = 0, len(S) - 1, 0
while l < r:
    lh = (lh * P + to_int(S[l])) % M
    rh = (rh + re * to_int(S[r])) % M
    re = re * P % M
    l, r = l + 1, r - 1

    if lh == rh:
        ans += 2
        lh, rh, re = 0, 0, 1

if l == r or lh != 0 or rh != 0:
    ans += 1

print(ans)
