from heapq import *


# g = {node: (cost, neigh)}
def dijkstra(n, root, g):
	dist = [float("inf")]*n
	dist[root] = 0
	prev = [-1]*n

	pq = [(0, root)]
	heapify(pq)
	visited = set([])

	while len(pq) != 0:
		_, node = heappop(pq)

		if node in visited: continue
		visited.add(node)

		# In case of disconnected graphs
		if node not in g:
			continue

		for cost, neigh in g[node]:
			alt = dist[node] + cost
			if alt < dist[neigh]:
				dist[neigh] = alt
				prev[neigh] = node
				heappush(pq, (alt, neigh))
	return dist
	

line = input()
while line != "0 0 0 0":
	n, m, q, s = map(int, line.split())

	g = {}
	for i in range(n):
		g[i] = [(0, i)]

	for i in range(m):
		u, v, w = map(int, input().split())
		g[u].append((w, v))

	
	dist = dijkstra(n, s, g)
	for _ in range(q):
		task = int(input())
		print(dist[task] if dist[task] < float("inf") else "Impossible")

	line = input()
	
