t = int(input())

# -> (2k+1)^2, (2k+1)^2 + 1, ...
# |
# v
# (2k)^2
# (2k)^2 + 1
# .
# .
# .

for _ in range(t):
    r, c = map(int, input().split())
    

    if r >= c:
        rr = 2*(r//2)
        rm = r%2
        rs = rr**2 + rm
        if r%2:
            print(rs + c -1)
        else:
            print(rs - c + 1)
    else:
        cr = 2*((c+1)//2)-1
        cm = not c%2
        cs = cr**2 + cm
        if c%2:
            print(cs - r + 1)
        else:    
            print(cs + r - 1)

