
t = int(input())

for _ in range(t):
    x = int(input())

    divs = []
    for i in range(2, int(x ** 0.5 + 1)):
        if x % i == 0:
            divs.append(i)

            if i * i != x:
                divs.append(x // i)

    divs.sort()
    ans = [(x+1, 1, 1)]
    for i in range(len(divs)):
        for j in range(i+1, len(divs)):
            if divs[j] % divs[i] == 0:
                break
        else:
            ans.append((divs[i] + 1, 1, 0))

    if x != 1 and len(divs) == 0:  # prime
        ans.append((2, 1, 0))

    print(len(ans))
    for i in range(len(ans)):
        print(*ans[i])
