L, H, k = map(int, input().split())

poster = [["_"]*L for _ in range(H)]

ch = 'a'
for i in range(k):
    l, h, a, b = map(int, input().split())

    for j in range(l):
        for k in range(h):
            poster[min(b + k, H-1)][min(a + j, L-1)] = ch
    ch = chr(1+ord(ch))

for x in poster:
    print("".join(x))
