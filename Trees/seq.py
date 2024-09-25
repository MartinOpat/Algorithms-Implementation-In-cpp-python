
mod = 10**9+7

s = input()
n = len(s)

oc = 0
bc = 1
ic = 0

for c in s:
    if c == "1":
        oc += bc % mod
        oc %= mod

    elif c == "0":
        ic += oc %mod
        ic %= mod

    else:
        # Double branches
        ic = (2*ic + oc) % mod
        oc = (2*oc + bc) % mod

        bc *= 2
        bc %= mod

print(ic)