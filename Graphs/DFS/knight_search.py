# from functools import lru_cache

# path="ICPCASIASG"
# n = int(input())
# s = input()

# def get_neigh(i, j):
#     global n

#     if i+2 < n and j+1 < n:
#         yield (i+2, j+1)
#     if i+2 < n and j-1 >= 0:
#         yield (i+2, j-1)
#     if i-2 >= 0 and j+1 < n:
#         yield (i-2, j+1)
#     if i-2 >= 0 and j-1 >= 0:
#         yield (i-2, j-1)
#     if i+1 < n and j+2 < n:
#         yield (i+1, j+2)
#     if i+1 < n and j-2 >= 0:
#         yield (i+1, j-2)
#     if i-1 >= 0 and j+2 < n:
#         yield (i-1, j+2)
#     if i-1 >= 0 and j-2 >= 0:
#         yield (i-1, j-2)


# @lru_cache(maxsize=None)
# def dfs(i, j, p_idx, history=set()):
#     global n, path
    
#     if (i, j, p_idx) in history:
#         return False
#     history.add((i, j, p_idx))

#     if p_idx == len(path):
#         return True
    
#     ans = False
#     for ni, nj in get_neigh(i, j):
#         if s[ni*n + nj] == path[p_idx]:
#             ans = ans or dfs(ni, nj, p_idx+1)
#         else:
#             ans = ans or dfs(ni, nj, p_idx)
#     return ans
        

# for i, c in enumerate(s):
#     if c == "I":
#         # print(f"Entering bfs with i={i%n} j={i//n}")
#         if dfs(i%n, i//n, 1):
#             print("YES")
#             exit()
# print("NO")

from functools import lru_cache

path="ICPCASIASG"
n = int(input())
s = input()

def get_neigh(i, j):
    global n

    if i+2 < n and j+1 < n:
        yield (i+2, j+1)
    if i+2 < n and j-1 >= 0:
        yield (i+2, j-1)
    if i-2 >= 0 and j+1 < n:
        yield (i-2, j+1)
    if i-2 >= 0 and j-1 >= 0:
        yield (i-2, j-1)
    if i+1 < n and j+2 < n:
        yield (i+1, j+2)
    if i+1 < n and j-2 >= 0:
        yield (i+1, j-2)
    if i-1 >= 0 and j+2 < n:
        yield (i-1, j+2)
    if i-1 >= 0 and j-2 >= 0:
        yield (i-1, j-2)


@lru_cache(maxsize=None)
def dfs(i, j, p_idx):
    global n, path
    

    if p_idx == len(path):
        return True
    
    for ni, nj in get_neigh(i, j):
        if s[ni*n + nj] == path[p_idx]:
            if dfs(ni, nj, p_idx+1):
                return True
        

for i in range(n):
    for j in range(n):
        if dfs(i, j, 0):
            print("YES")
            exit()
print("NO")
