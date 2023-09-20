#
# def hash(array):
#     ans = 0
#     for i in range(len(array)):
#         ans += 10**i * array[i]
#     return ans
#
#
# dp = {}
# def solve(ans, hist):
#     hist_hash = hash(hist)
#     if (ans, hist_hash) not in dp:
#         for i in range(len(hist)):
#             if hist[i] == 0:
#                 if i == 0 and ans == "":
#                     continue
#                 dp[(ans, hist_hash)] = int(ans + str(i))
#                 break
#         else:
#             new_ans = float("inf")
#             for i in range(len(hist)):
#                 if ans == "" and i == 0:
#                     continue
#                 hist[i] -= 1
#                 new_ans = min(new_ans, solve(ans + str(i), hist))
#                 hist[i] += 1
#
#             dp[(ans, hist_hash)] = new_ans
#
#     return dp[ans, hist_hash]
#
#
# digits = input()
# hist = [0]*10
#
# for digit in digits:
#     hist[int(digit)] += 1
#
# print(solve("", hist))

###############################################################33

digs = input()
hist = 10*[0]
for x in digs:
    hist[int(x)] += 1

m = min(hist)
index = hist.index(m)

for i in range(1, 10):
    if index == 0 and m == hist[i]:
        m = hist[i]
        index = i
        break

if index == 0:
    print("1" + (m+1)*"0")
else:
    print(str(index)*(m+1))
