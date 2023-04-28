from collections import deque

h, n, m = map(int, input().split())

maze = ""
for i in range(n):
    maze += "".join(input().split())


def neighsOdd(i, j):
    if j+1 < m:
        yield i, j+1

        if i+1 < n:
            yield i+1, j+1

        if i-1 >= 0:
            yield i-1, j+1

    if i-1 >= 0:
        yield i-1, j

    if i+1 < n:
        yield i+1, j

    if j-1 >= 0:
        yield i, j-1


def neighsEven(i, j):
    if i-1 >= 0:
        yield i-1, j

        if j-1 >= 0:
            yield i-1, j-1

    if j-1 >= 0:
        yield i, j-1

    if i+1 < n:
        yield i+1, j

        if j-1 >= 0:
            yield i+1, j-1

    if j+1 < m:
        yield i, j+1


def bfs(graph):
    q = deque([])
    sizes = []
    visited = set([])
    for k in range(m*n):
        if graph[k] != "." or k in visited:
            continue

        visited.add(k)
        i, j = k // m, k % m
        # print(graph)
        # print("found", k, i, j)
        q.append((i, j))

        size = 0
        while len(q) != 0:
            size += 1
            # print(q)
            i, j = q.pop()
            # print("start", i, j)

            # this bitch be a hexagon so neighbours are annoying
            if i % 2 == 0:
                for vi, vj in neighsEven(i, j):
                    # print("even", vi, vj)
                    k = m*vi + vj
                    if graph[k] == "." and k not in visited:
                        visited.add(k)
                        q.append((vi, vj))
            else:
                for vi, vj in neighsOdd(i, j):
                    # print("odd", vi, vj)
                    k = m * vi + vj
                    if graph[k] == "." and k not in visited:
                        visited.add(k)
                        q.append((vi, vj))

        sizes.append(size)
    return sizes


sizes = bfs(maze)
sizes.sort(reverse=True)
# print(sizes)

ans = 0
while h > 0:
    h -= sizes[ans]
    ans += 1
print(ans)
