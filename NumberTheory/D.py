q = int(input())

for _ in range(q):
    l, r, x = map(int, input().split())

    if x % 2 == 1 or x // 2 < l or x // 2 > r:
        print(0)
    else:
        print(x // 2 - l + 1)
