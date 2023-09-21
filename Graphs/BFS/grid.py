from collections import deque

n, m = map(int, input().split())


def get_grid_neighs(i, j):
    if i + grid[i][j] < n:
        yield i + grid[i][j], j

    if i - grid[i][j] >= 0:
        yield i - grid[i][j], j

    if j + grid[i][j] < m:
        yield i, j + grid[i][j]

    if j - grid[i][j] >= 0:
        yield i, j - grid[i][j]


def bfs(roots):
    q = deque(roots)
    explored = set(roots)
    distances = [[float("inf")]*m for _ in range(n)]
    distances[0][0] = 0

    while len(q) != 0:
        v = q.popleft()
        i, j = v

        for neigh in get_grid_neighs(i, j):
            i_neigh, j_neigh = neigh
            if neigh not in explored:
                explored.add(neigh)
                q.append(neigh)
                distances[i_neigh][j_neigh] = distances[i][j] + 1
    return distances


grid = []
for _ in range(n):
    grid.append([int(x) for x in input()])

ans = bfs([(0, 0)])
print(ans[n-1][m-1] if ans[n-1][m-1] < float("inf") else -1)
