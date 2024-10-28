import fractions

n = int(input())
ls = list(map(int, input().split()))

avg = fractions.Fraction(sum(ls), n)
ls = [x - avg for x in ls]

cumsum = 0
l, r = 0, n - 1
order = []
cont = True

while cont:
    cont = False

    # left
    while l <= r:
        curr = 0
        i = l
        while True:
            curr += ls[i]
            if cumsum - curr > 0:
                break
            if curr > 0 or not l <= i + 1 <= r:
                break
            i += 1
        
        if cumsum - curr > 0:
            break
        
        if l <= i:
            for j in range(l, i + 1):
                order.append(j)
            cumsum -= sum(ls[l:i + 1])
            l = i + 1
            cont = True

    # right
    while l <= r:
        curr = 0
        i = r
        while True:
            curr += ls[i]
            if cumsum - curr > 0:
                break
            if curr > 0 or not l <= i - 1 <= r:
                break
            i -= 1

        if cumsum - curr > 0:
            break

        if i <= r:
            for j in range(r, i - 1, -1):
                order.append(j)
            cumsum -= sum(ls[i:r + 1])
            r = i - 1
            cont = True

if len(order) == n:
    print(" ".join([str(x + 1) for x in order][::-1]))
else:
    print("impossible")
