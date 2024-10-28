from collections import deque

n, k = map(int, input().split())

ins = [list(map(int, input().split())) for i in range(n)]

if n == 1:
    print(0)
    exit()

def get_new_blinker(n, o):
    if (o+1)%4 == n:
        return -1
    elif (o-1+4)%4 == n:
        return 1
    else:
        return 0

# state = (node, from, blinker, k lfet)

dist = {}
q = deque()
for neigh in ins[0]:
    if neigh == 0:
        continue
    state = (neigh, 1, 0, k)
    dist[state] = 1
    q.append(state)

while q:
    # print(q)
    state = q.popleft()
    node, from_node, blinker, kleft = state
    if node == n:
        break
    old_dir = ins[node-1].index(from_node)
    new_dirs = [(old_dir+1)%4, (old_dir+2)%4, (old_dir-1)%4]

    for new_dir in new_dirs:
        neigh = ins[node-1][new_dir]
        if neigh == 0:
            continue
        new_blinker = get_new_blinker(new_dir, old_dir)
        # print(old_dir, new_dir, neigh, new_blinker)
        new_kleft = kleft - int(new_blinker!=blinker and new_blinker!=0)
        if new_kleft < 0:
            continue
        new_state = (neigh, node, new_blinker, new_kleft)
        if new_state in dist and dist[new_state] <= dist[state] + 1:
            continue

        dist[new_state] = dist[state]+1
        q.append(new_state)
        
# print(dist)

ans = float("inf")
for key in dist:
    if key[0] == n:
        ans = min(ans, dist[key])

print(ans if ans != float("inf") else "impossible")