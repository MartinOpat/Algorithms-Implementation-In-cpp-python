from bisect import bisect_left, bisect_right

n, q = map(int, input().split())
ds = [int(x) for x in input().split()]

ds.sort()

for i in range(q):
    t, d = map(int, input().split())
    if not ds:
        print(-1)
        continue


    index = bisect_left(ds, d)
    if t == 1:
        if d >= ds[-1]:
            print(-1)
            continue

        # print(index)

        while ds[index] == d:
            index += 1

    else:
        if ds[0] > d:
            print(-1)
            continue
        # print(index)

        if index >= len(ds):
            index -= 1

        while ds[index] > d:
            index -= 1

    print(ds[index])
    ds = ds[:index] + ds[index+1:]


