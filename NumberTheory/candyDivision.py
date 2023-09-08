n = int(input())

ans = []
for i in range(1, int(n**0.5+1)):
    if n % i == 0:
        ans.append(i-1)

        if i*i != n:
            ans.append(n//i-1)

# print(ans)
ans.sort()
print(*ans)