# line = input()
# while line != "0 0 0 0":
#     n, m, q, s = map(int, line.split())
#
#     adj_m = [[float("inf")]*n]*n
#     for i in range(n):
#         adj_m[i][i] = 0
#
#     for i in range(m):
#         u, v, w = map(int, input().split())
#         adj_m[u][v] = w
#         adj_m[v][u] = w
#
#     for k in range(n):
#         for i in range(n):
#             for j in range(n):
#                 if adj_m[i][j] > adj_m[i][k] + adj_m[k][j]:
#                     adj_m[i][j] = adj_m[i][k] + adj_m[k][j]
#
#
#
#     line = input()
#