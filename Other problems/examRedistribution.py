
n = int(input())
rooms = [int(x) for x in input().split()]

maximum = max(rooms)
index_max = rooms.index(maximum)

if 2*maximum <= sum(rooms):
    ans = [i+1 for i in range(n)]
    ans.remove(index_max+1)
    ans = [index_max+1] + ans
    print(*ans)

else:
    print("impossible")