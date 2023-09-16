from collections import deque

n, m = map(int, input().split())

g = {}
parent = [{"A": (), "B": (), "C": ()}]
for i in range(1, n+1):
    g[i] = {"A": [], "B": [], "C": []}
    parent.append({"A": (), "B": (), "C": ()})

for i in range(m):
    s1, s2 = input().split()

    s1 = (int(s1[:-1]), s1[-1])
    s2 = (int(s2[:-1]), s2[-1])

    g[s1[0]][s1[1]].append(s2)
    g[s2[0]][s2[1]].append(s1)


goal = set([])
labels = {"A", "B", "C"}
for switch, label in g[1]["A"]:
    if label == "A":
        goal.add((switch, "B"))
        goal.add((switch, "C"))
    else:
        goal.add((switch, "A"))


q = deque([(1, "A")])
visited = set([])
# visited = {(1, "A")}
parent[1]["A"] = (-1, "", 1)
found = False

while len(q) != 0:
    # print(q)
    switch, label = q.popleft()

    if label == "A":
        for neigh in g[switch]["B"]:
            neigh_switch, neigh_label = neigh
            if neigh not in visited:
                visited.add(neigh)
                parent[neigh_switch][neigh_label] = (switch, "B", parent[switch][label][2]+1)
                q.append(neigh)

        for neigh in g[switch]["C"]:
            neigh_switch, neigh_label = neigh
            if neigh not in visited:
                visited.add(neigh)
                parent[neigh_switch][neigh_label] = (switch, "C", parent[switch][label][2]+1)
                q.append(neigh)

    else:
        for neigh in g[switch]["A"]:
            neigh_switch, neigh_label = neigh
            if neigh not in visited:
                visited.add(neigh)
                parent[neigh_switch][neigh_label] = (switch, "A", parent[switch][label][2]+1)
                q.append(neigh)

    if (switch, label) in goal:
        found = True
        break

# for x in parent:
#     print(x)
#
# print(goal)
if not found:
    print("Impossible")
    exit()

ans = ["B"]*(n+1)
while switch != 1 or label != "A":
    # print(switch, label)
    # ans[switch] = label

    switch, label, _ = parent[switch][label]
    if label != "A":
        ans[switch] = label

    if label == "A":
        if len(parent[switch]["B"]) == 0:
            label = "C"
        elif len(parent[switch]["C"]) == 0:
            label = "B"
        elif parent[switch]["B"][2] < parent[switch]["C"][2]:
            label = "B"
        else:
            label = "C"
    else:
        label = "A"

switch, label, _ = parent[switch][label]
if label != "A":
    ans[switch] = label

# print(switch, label)

# print ans
print("".join(ans[1:]))
