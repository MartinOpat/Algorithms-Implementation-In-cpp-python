from collections import OrderedDict
t = int(input())

for _ in range(t):
    m, r = map(int, input().split())
    movies = [int(x) for x in input().split()]
    stack :OrderedDict = OrderedDict.fromkeys([i+1 for i in range(m)])

    ans = []
    for movie in movies:
        print(stack)
        index = stack.keys()
        ans.append(index)
        stack.move_to_end(movie, last=False)
    print(*ans)

