from collections import deque

n = int(input())

ps = [int(p.replace('.', '')) for p in input().split()]


bins = [deque() for _ in range(5)]
for p in ps:
    bins[p%5].append(p)


ans = sum(bins[0])
ans += sum(bins[1]) - len(bins[1])
ans += sum(bins[2]) - 2*len(bins[2])

while bins[3] and bins[4]:
    ans += bins[3].pop() + bins[4].pop()-2

while len(bins[3]) >= 2:
    ans += bins[3].pop() + bins[3].pop()-1


while bins[3]:
    ans += bins[3].pop()

while len(bins[4]) >= 3:
    ans += bins[4].pop() + bins[4].pop() + bins[4].pop() -2

while bins[4]:
    ans += bins[4].pop()

print(f"{ans/100:.2f}")
