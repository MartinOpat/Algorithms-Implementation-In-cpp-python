
n, m, q = map(int, input().split())

while n != 0 or m != 0 or q != 0:

    graph = [[float("inf") if i != j else 0 for j in range(n)] for i in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        graph[u][v] = min(w, graph[u][v])

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if graph[i][j] > graph[i][k] + graph[k][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]

    for _ in range(q):
        u, v = map(int, input().split())

        if graph[u][v] < float("inf"):
            has_neg_cycle = False
            for i in range(n):
                if graph[u][i] < float("inf") and graph[i][v] < float("inf") and graph[i][i] < 0:
                    print("-Infinity")
                    break
            else:
                print(graph[u][v])
        else:
            print("Impossible")

    print()
    n, m, q = map(int, input().split())
