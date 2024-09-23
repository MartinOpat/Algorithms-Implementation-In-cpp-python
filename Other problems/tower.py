from itertools import permutations

nums = [int(x) for x in input().split()]
hs = nums[:6]
h1 = nums[6]
h2 = nums[7]

for p in permutations(hs):
    # print(p)
    t1 = p[:3]
    t2 = p[3:]

    s1 = sum(t1)
    s2 = sum(t2)
    # if t1 != sorted(t1) or t2 != sorted(t2):
    #     continue

    if (s1 == h1 and s2 == h2):
        print(" ".join(map(str, sorted(t1)[::-1])) + " " + " ".join(map(str, sorted(t2)[::-1])))
        exit()
    elif (s1 == h2 and s2 == h1):
        print(" ".join(map(str, sorted(t2)[::-1])) + " " + " ".join(map(str, sorted(t1)[::-1])))
        exit()
