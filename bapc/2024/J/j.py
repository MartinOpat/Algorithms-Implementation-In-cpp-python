n = int(input())

ap = 0
bp = 0

for i in range(n):
    a, b = map(int, input().split())

    if a < ap or b < bp:
        print("no")
        exit()
    ap = a
    bp = b
print("yes")