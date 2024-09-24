from collections import defaultdict, deque

n, m = map(int, input().split())
pa, pb = map(int, input().split())

g = defaultdict(set)
for _ in range(m):
    p1, p2 = map(int, input().split())
    g[p1].add(p2)
    g[p2].add(p1)

def bfs(g, roots, n):
    visited = set(roots)
    q = deque(roots)
    distances = [float("inf")]*n
    for root in roots:
        distances[root] = 0

    while q:
        node = q.popleft()

        for neigh in g[node]:
            if neigh not in visited:
                distances[neigh] = distances[node] + 1
                visited.add(neigh)
                q.append(neigh)

    return distances

d1 = bfs(g, [pa], n)
d2 = bfs(g, [pb], n)

ans = float("inf")
for i in range(n):
    temp = max(d1[i], d2[i])
    ans = min(ans, temp)

print(ans)