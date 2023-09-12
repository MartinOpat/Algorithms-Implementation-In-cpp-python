n = int(input())
res = [int(x) for x in input().split()]

hist = [0]*10001
ans = 0
for x in res:
    if hist[x] == 0:
        hist[x] = x
        ans += x+1
    else:
        hist[x] -= 1

print(ans)
