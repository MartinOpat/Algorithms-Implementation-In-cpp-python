from sys import setrecursionlimit
setrecursionlimit(1000000000)

p = input()
s = input()
m = 10 ** 9 + 7


# Python program to count number of times S appears
# as a subsequence in T

def f(i, j, s, t):

    # if we have reached the end of T
    if j >= len(t):
        return 1

    # if we have reached the end of S
    if i >= len(s):
        return 0

    # if remaining characters in T are less than remaining characters in S
    if len(t) - j > len(s) - i:
        return 0

    # if we have already solved this subproblem
    if dp[i][j] != -1:
        return dp[i][j]

    if s[i] == t[j]:
        # count of S as subsequence in T where S and T are both
        # considering the current character
        count1 = f(i + 1, j + 1, s, t) % m

        # count of S as subsequence in T where T is considering
        # the current character but S is not
        count2 = f(i + 1, j, s, t) % m
        dp[i][j] = (count1 + count2) % m
        return dp[i][j]

    # if current characters of S and T don't match
    dp[i][j] = f(i + 1, j, s, t) % m
    return dp[i][j]


def rotate(strg):
    return strg[-1:] + strg[:-1]


ans = 0
tried = set([])
for i in range(len(s)):
    if s in tried:
        continue
    tried.add(s)
    dp = [[-1 for _ in range(len(s))] for __ in range(len(p))]
    ans += f(0, 0, p, s) % m
    s = rotate(s)

print(ans % m)
