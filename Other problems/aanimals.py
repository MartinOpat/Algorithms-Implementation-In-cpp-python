from collections import defaultdict

n = int(input())
k = int(input())

items = defaultdict(set)

for _ in range(k):
    s = input().split()
    i = int(s[0])
    x = s[1]

    items[i].add(x)

m = int(input())
l = [input() for _ in range(m)]

i_need = 0
i_shop = 0
path = []
while i_need < m and i_shop < n:
    if l[i_need] in items[i_shop]:
        i_need += 1
        # if not path or path[-1] != i_shop:
        path.append(i_shop)

    else:
        i_shop += 1

if i_need != m:
    print("impossible")
    exit()

i_need = m-1
i_shop = n-1
path2 = []
while i_need >= 0 and i_shop >= 0:
    if l[i_need] in items[i_shop]:
        i_need -= 1
        # if not path2 or path2[-1] != i_shop:
        path2.append(i_shop)

    else:
        i_shop -= 1

# print(path)
# print(path2)
if len(path) == len(path2) and all([path[len(path)-i-1] == path2[i] for i in range(len(path))]):
    print("unique")
else:
    print("ambiguous")




