from heapq import heappush, heappop, heapify

n, m = map(int, input().split())
cs = list(map(int, input().split()))
ses = [tuple([int(x) - 1 for x in input().split()]) for _ in range(m)]

# Sort by end date
ses.sort(key=lambda x: (x[1],  x[1]-x[0]))

# Remove overlapping
temp= [ses[0]]
for (s, e) in ses[1:]:
    if s <= temp[-1][0]:
        continue
    temp.append((s, e))
temp.append((n, n))
ses = temp

dp = [0]*n
mdpj = 0
h = []
j = 0
heapify(h)
for i in range(n):
    dp[i] = cs[i] + mdpj

    # Update min(dp[j]) for j in [ki, i]
    heappush(h, (dp[i], i))
    if j < len(ses) and i == ses[j][1]:
        while h[0][1] < ses[j][0]:
            try:
                heappop(h)
            except:
                break
        mdpj = h[0][0]
        j += 1

dp[-1] = min(dp[-1], mdpj)
print(dp[-1])
