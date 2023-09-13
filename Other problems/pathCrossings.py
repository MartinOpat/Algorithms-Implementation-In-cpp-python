p, n = map(int, input().split())

pings = []
meet_dist = 1000
meet_time = 10
for _ in range(n):
    pings.append([int(x) for x in input().split()])

pings = sorted(pings, key=lambda x: x[3])
# print(pings)
crossed = []

for i in range(n):
    for j in range(i+1, n):
        if abs(pings[i][3] - pings[j][3]) > meet_time:
            break
        if pings[i][0] != pings[j][0] and (pings[i][1] - pings[j][1])**2 + (pings[i][2] - pings[j][2])**2 <= meet_dist**2:
            crossed.append((pings[i][0], pings[j][0]))

print(len(crossed))
for x in crossed:
    print(*x)