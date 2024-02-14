# Eathing everything efficiently
from collections import deque

n, m = map(int, input().split())
c = list(map(int, input().split()))

if n == 1:  # A bit of a special case
    print(c[0])
    exit()

graph = {}
nodes = set()
for i in range(m):
    a, b = map(int, input().split())
    if a not in graph:
        graph[a] = []
    graph[a].append(b)
    nodes.add(a)
    nodes.add(b)

leafs = nodes - set(graph.keys()) 

sorted_nodes = []
visited = set()

def topological_sort(node):
    visited.add(node)
    if node in graph:
        for child in graph[node]:
            if child not in visited:
                topological_sort(child)
    sorted_nodes.append(node)

for node in nodes:
    if node not in visited:
        topological_sort(node)

# print(sorted_nodes)


dp = [0] * (n + 1)
for v in sorted_nodes:
    if v in leafs:
        dp[v] = c[v]
    else:
        for u in graph[v]:
            dp[v] = max(dp[v], max(c[v] + dp[u]/2, dp[u]))
print("{:.7f}".format(dp[0]))

