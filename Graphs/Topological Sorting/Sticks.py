import random

n, m = 0, 0
edg = [[] for _ in range(1000000)]
indeg = [0] * 1000000

def top_sort():
    random.seed(2009)
    global n, m
    n, m = map(int, input().split())
    if n == 0:
        exit(0)

    indeg[:n] = [0] * n
    for _ in range(m):
        a, b = map(int, input().split())
        a, b = a - 1, b - 1
        indeg[b] += 1
        edg[a].append(b)

    q = []
    for i in range(n):
        if indeg[i] == 0:
            q.append(i)
    ret = []

    happy = True
    for _ in range(n):
        if not q:
            happy = False
            break

        r = random.randint(0, len(q) - 1)
        q[0], q[r] = q[r], q[0]

        v = q.pop(0)
        ret.append(v + 1)

        for w in edg[v]:
            indeg[w] -= 1
            if indeg[w] == 0:
                q.append(w)

    for i in range(n):
        edg[i].clear()

    if happy:
        for i in range(n):
            print(ret[i])
    else:
        print("IMPOSSIBLE")


top_sort()
