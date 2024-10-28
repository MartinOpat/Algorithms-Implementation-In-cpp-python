n,m = map(int, input().split())

ss = list(map(int, input().split()))
ss = [(s, i) for i, s in enumerate(ss)]
ps = list(map(int, input().split()))

ss.sort(reverse=True)

skill_sums = [0]*m

bins = [[] for _ in range(m)]
for (s, idx) in ss:
    besti = -1
    best = (0, float("inf"))
    for i in range(m):
        curr = (ps[i] * s, (s + skill_sums[i]))
        # print(idx, i, curr)
        if curr[0]*best[1] > best[0]*curr[1]:
            best = curr
            besti = i
    bins[besti].append(str(idx+1))
    skill_sums[besti] += s
    # print(idx, s, besti)
    # print()

for i in range(m):
    print(len(bins[i]), " ".join(bins[i]))

# print(skill_sums)

# # Check bins
# def calc_score(ci, bi):
#     global bins, skill_sums, ps
#     t = skill_sums[bi]+ss[ci][0] if str(ss[ci][1]+1) not in bins[bi] else skill_sums[bi] 
#     return ps[bi] * ss[ci][0] / t


# for i, (s, idx) in enumerate(ss):
#     best = float("-inf")
#     bestjs = []
#     for j, b in enumerate(bins):
#         curr = calc_score(i, j)
#         print(idx+1, s, j, curr)
#         if curr > best:
#             curr = best
#             bestjs = [j]
#         elif curr == best:
#             bestjs.append(j)
    
#     for j in bestjs:
#         if str(idx+1) in bins[j]:
#             print(i,"is good")
#             break
#     else:
#         print(i, "is bad")
