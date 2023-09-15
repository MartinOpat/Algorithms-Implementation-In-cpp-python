from heapq import *

line = input()
while line != "0 0 0 0":
    n, m, q, s = map(int, line.split())

    g = {}
    for i in range(n):
        g[i] = [(0, i)]

    for i in range(m):
        u, v, w = map(int, input().split())
        g[u].append((w, v))

    dist = [float("inf")]*n
    dist[s] = 0
    prev = [-1]*n

    pq = [(0, s)]
    heapify(pq)
    visited = set([])
    # for v in range(n):
    #     pq.append((dist[v], v))
    # heapify(pq)

    while len(pq) != 0:
        _, u = pq.pop()
        # print(dist)
        # print(u)

        if u in visited:
            continue
        visited.add(u)

        for w, v in g[u]:
            w = -w
            alt = dist[u] + w
            # print(v, alt)
            if alt < dist[v]:
                dist[v] = alt
                prev[v] = u
                pq.append((-alt, v))
        # print()

    # print(dist)
    for _ in range(q):
        task = int(input())
        print(dist[task] if dist[task] < float("inf") else "Impossible")

    line = input()
