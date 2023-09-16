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

    while len(pq) != 0:
        _, u = heappop(pq)

        # To avoid having to delete element from pq
        if u in visited:
            continue
        visited.add(u)

        # In case of disconnected graphs
        if u not in g:
            continue

        for w, v in g[u]:
            alt = dist[u] + w
            # print(v, alt)
            if alt < dist[v]:
                dist[v] = alt
                prev[v] = u
                heappush(pq, (alt, v))

    for _ in range(q):
        task = int(input())
        print(dist[task] if dist[task] < float("inf") else "Impossible")

    line = input()
