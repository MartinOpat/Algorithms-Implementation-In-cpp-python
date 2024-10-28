n,m,r = map(int, input().split())

teams = [[i+1, input().count("P")] for i in range(n)]

p_count = 0
for team in teams:
    p_count += team[1]

b = n-1
while p_count > 0:
    if teams[b][1] == 0:
        b -= 1
        continue
    
    sc = input().count("y")
    p_count -= 1
    teams[b][1] -= 1
    if sc > 0:
        sc -= 3
    else:
        continue
    teams = teams[:b-sc] + [teams[b]] + teams[b-sc:b] + teams[b+1:]
    

for i, team in enumerate(teams):
    if team[0] == r:
        print(i+1)
        exit(0)
