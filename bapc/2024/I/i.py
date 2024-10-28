# Slightly inspired by Ragnar's solution
n, k = map(int, input().split())
rides = [list(map(int, input().split())) for _ in range(n)]
discounts = [list(map(int, input().split())) for _ in range(k)]

lastride = [n - 1] * 2000001
for i in range(n - 1):
    for day in range(rides[i][0], rides[i + 1][0]):
        lastride[day] = i

dp = [float('inf')] * (n + 1)
dp[0] = 0

for i in range(n):
    cost = dp[i]
    dp[i + 1] = min(dp[i + 1], cost + rides[i][1])
    start_day = rides[i][0]
    for d, t, p in discounts:
        max_rides = i + t
        max_days = lastride[start_day + d - 1] + 1
        j = min(max_rides, max_days)
        dp[j] = min(dp[j], cost + p)

print(dp[n])
