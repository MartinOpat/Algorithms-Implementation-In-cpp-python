n = int(input())

def count(k):
    return k**2 * (k**2-1) //2 -4*(k-1)*(k-2)

for i in range(1, n+1):
    print(count(i))

