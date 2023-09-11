from collections import Counter

t = int(input())

for _ in range(t):
    n = int(input())
    q = input()

    hist1 = Counter(q)
    times1 = dict(zip(set(q), [0]*n))
    times2 = dict(zip(set(q), [0]*n))
    time1 = 0
    time2 = 0

    sorted_teams = set([])
    q_ideal = ""
    for team in q[::-1]:
        if team in sorted_teams:
            continue

        q_ideal = team*hist1[team] + q_ideal
        sorted_teams.add(team)
    for j, team in enumerate(q):
        times1[team] = 5*j*hist1[team]

    for j, team in enumerate(q_ideal):
        times2[team] = 5*j*hist1[team]

    ans = 0
    for j in times1:
        ans += times1[j] - times2[j]
    print(ans)

    # w_team_count = n
    # for team in q:
    #     hist1[team] -= 1
    #     if hist1[team] == 0:
    #         w_team_count -= 1
    #     time1 += 5*w_team_count
    #
    # w_team_count = n
    # for team in q_ideal:
    #     hist2[team] -= 1
    #     if hist2[team] == 0:
    #         w_team_count -= 1
    #     time2 += 5*w_team_count
    # print(time1 - time2)










