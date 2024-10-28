import fractions

n = int(input())
a = list(map(int, input().split()))

avg = fractions.Fraction(sum(a), n)
a = [x - avg for x in a]

s = 0


l, r = 0, n - 1
def take(i, d):
    taken = 0
    while 1:
        taken += a[i]
        if s - taken > 0:
            return -1
        if taken > 0 or not l <= i + d <= r:
            return i
        i += d


ans = []
change = True
while change:
    change = False
    while l <= r and (x := take(l, 1)) != -1:
        ans += range(l, x + 1)
        s -= sum(a[l:x + 1])
        l = x + 1
        change = True
    while l <= r and (x := take(r, -1)) != -1:
        ans += range(r, x - 1, -1)
        s -= sum(a[x:r + 1])
        r = x - 1
        change = True

if len(ans) == n:
    print(*(x + 1 for x in reversed(ans)))
else:
    print("impossible")