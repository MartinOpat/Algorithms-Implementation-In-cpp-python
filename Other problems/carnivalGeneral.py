from itertools import permutations

n = int(input())

rankings = []
no_good = [set([])]
U = set([x for x in range(n)])
good = [U]
for i in range(n-1):
    ranking = [int(x) for x in input().split()]
    rankings.append(ranking)

    if i % 2 == 0:
        temp = set(ranking[(i + 1) // 2 + 1:])
        no_good.append(temp)
        good.append(U.difference(temp))

    else:
        temp = set(ranking[(i + 1) // 2:])
        no_good.append(temp)
        good.append(U.difference(temp))


def find_sol(ans):
    m = len(ans)
    if m == n:
        print(*ans)
        exit()

    for i in range(m+1):
        if i == 0:
            if ans[i] not in no_good[m] and m not in no_good[ans[i]]:
                find_sol([m] + ans)
        elif i == m:
            if ans[i-1] not in no_good[m] and m not in no_good[ans[i-1]]:
                find_sol(ans + [m])
        else:
            if ans[i] not in no_good[m] and m not in no_good[ans[i]]:
                if ans[i - 1] not in no_good[m] and m not in no_good[ans[i - 1]]:
                    find_sol(ans[:i] + [m] + ans[i:])

find_sol([0, 1])
# print(no_good)

# # set 3
# if n <= 8:
#     for candidate in permutations([x for x in range(n)], n):
#         for i in range(n-1):
#             smaller = min(candidate[i], candidate[i+1])
#             larger = max(candidate[i], candidate[i+1])
#
#             if smaller in no_good[larger]:
#                 break
#         else:
#             print(*candidate)
#             exit()
#
# # set 2
# elif rankings[0][0] == rankings[-1][0]:
#     ans = []
#     used = {n - 1}
#     last = n - 1
#     ans.append(n-1)
#     while len(used) < n:
#         candidate1 = n - 1
#         while candidate1 >= 2*last + 1:
#             if candidate1 not in used:
#                 ans.append(candidate1)
#                 used.add(candidate1)
#                 last = candidate1
#                 break
#             candidate1 -= 1
#         else:
#             candidate2 = (last - 1) // 2
#             while candidate2 in used:
#                 candidate2 -= 1
#             ans.append(candidate2)
#             used.add(candidate2)
#             last = candidate2
#     print(*ans)
#
# # set 1
# else:
#     print(*[int(x) for x in range(n)][::-1])



