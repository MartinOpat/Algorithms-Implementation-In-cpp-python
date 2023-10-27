def solve(n):
    if n == 0: return []
    if n == 10: return [5, 5]
    s = str(n)
    l, r = (len(s)+1)//2, len(s)//2
    p = lambda s: s + ''.join(reversed(s[:r]))
    x = int(str(n)[:l])
    if int(p(str(x))) > n: x -= 1
    a = int(p(str(x)))
    return solve(n-a) + [a]
s = solve(int(input()))
print(len(s), *s, sep='\n')
