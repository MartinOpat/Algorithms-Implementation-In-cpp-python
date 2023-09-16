from heapq import *

n = int(input())
items = [0] + [int(x) for x in input().split()]
m = int(input())

g = {}

for i in range(m):
    u, v, w = map(int, input().split())
    if u in g:
        g[u].append((w, v))
    else:
        g[u] = [(w, v)]

    if v in g:
        g[v].append((w, u))
    else:
        g[v] = [(w, u)]

dists = [float("inf")]*(n+1)
dists[1] = 0
pick_ups = [0]*(n+1)
pick_ups[1] = items[1]

pq = [(0, items[1], 1)]
heapify(pq)
visited = set([])

while len(pq) != 0:
    _, _, u = heappop(pq)

    # To avoid having to delete element from pq
    if u in visited:
        continue
    visited.add(u)

    # In case of disconnected graphs
    if u not in g:
        continue

    for w, v in g[u]:
        alt_dist = dists[u] + w
        alt_item = pick_ups[u] + items[v]

        if alt_dist < dists[v]:
            dists[v] = alt_dist
            pick_ups[v] = alt_item
            heappush(pq, (alt_dist, alt_item, v))

        elif alt_dist == dists[v] and alt_item > pick_ups[v]:
            pick_ups[v] = alt_item
            heappush(pq, (alt_dist, alt_item, v))

# print(dists)
if dists[n] < float("inf"):
    print(dists[n], pick_ups[n])
else:
    print("impossible")

