from collections import deque

n, m = map(int, input().split())
grid = [[int(x) for x in input()] for i in range(n)]

grid = [[0]*m] + grid + [[0]*m]
for i in range(len(grid)):
    grid[i] = [0] + grid[i] + [0]

# [print(*x) for x in grid]


def get_grid_neighs(i, j, i_max, j_max):
    if i - 1 >= 0:
        yield i-1, j

    if j - 1 >= 0:
        yield i, j-1

    if i + 1 < i_max:
        yield i+1, j

    if j + 1 < j_max:
        yield i, j+1


def bfs(roots, ans):
    q = deque(roots)
    explored = set(roots)

    while len(q) != 0:
        v = q.pop()
        i, j = v
        # print(i, j)
        # grid[i][j] = 5

        for neigh in get_grid_neighs(i, j, n+2, m+2):
            i_neigh, j_neigh = neigh
            if grid[i_neigh][j_neigh] == 1:
                ans += 1
                # print(i, j, i_neigh, j_neigh)
            else:
                if neigh not in explored:
                    explored.add(neigh)
                    q.append(neigh)
    return ans


# grid_edges = []
# ans = 0
# for j in range(m):
#     if grid[0][j] == 1:
#         ans += 1 + (j == 0 or j == m-1)
#     else:
#         grid_edges.append((0, j))
#
#     if grid[n-1][j] == 1:
#         ans += 1 + (j == 0 or j == m-1)
#     else:
#         grid_edges.append((n - 1, j))
#
# for i in range(1, n-1):
#     if grid[i][0] == 1:
#         ans += 1
#     else:
#         grid_edges.append((i, 0))
#
#     if grid[i][m-1] == 1:
#         ans += 1
#     else:
#         grid_edges.append((i, m - 1))

# print("BFS")
ans = bfs([(0, 0)], 0)
# [print(*x) for x in grid]
# print()
# [print(*x) for x in grid]

print(ans)



