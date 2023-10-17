n, k = [int(i) for i in input().split()]
stats = {}
for i in range(n):
    stat, val = input().split()
    stats[stat] = int(val)

events = {}
for i in range(int(input())):
    stat, val = input().split()
    if stat not in events:
        events[stat] = []
    events[stat].append(int(val))

score = 0
best_sink = 0
bonus = []
for stat in events:
    best = max(events[stat])
    if stats[stat] < best:
        k -= best - stats[stat]
        stats[stat] = best
    count_max = 0
    count_other = 0
    for i in events[stat]:
        if i == stats[stat]:
            count_max += 1
        else:
            count_other += 1
            score += stats[stat]
    bonus.append(count_max*(stats[stat]+1) + count_other)
    best_sink = max(best_sink, count_max + count_other)

bonus.sort(reverse = True)
for i in bonus:
    if i<best_sink or k <= 0:
        break
    score += i
    k -= 1
if k > 0:
    score += best_sink * k
if k < 0:
    print(0)
else:
    print(score)