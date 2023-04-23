from math import ceil

n, m = map(int, input().split())

cs = []
for i in range(n):
    p, c = map(int, input().split())
    cs.append((p, c))


d_max = 2*10**9
d_min = 1


def calcMoney(day):
    money = 0
    for p, c in cs:
        money += max(0, p*day-c)
    return money

while True:
    ans = d_min + (d_max - d_min)//2

    if calcMoney(ans) >= m > calcMoney(ans - 1):
        break

    elif calcMoney(ans) >= m:
        d_max = ans-1

    else:
        d_min = ans+1

print(ans)
