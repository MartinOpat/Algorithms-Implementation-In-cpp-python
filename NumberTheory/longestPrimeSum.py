n = int(input())

if n%2:
    ans = 1 + (n-3)//2
else:
    ans = n // 2
    
print(ans)