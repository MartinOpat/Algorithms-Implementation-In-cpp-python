from bisect import bisect_left

n, q = map(int, input().split())
ds = [int(x) for x in input().split()]

ds.sort()

ds_set = [ds[0]]
ds_count = [1]
for i in range(1, n):
    if ds_set[-1] == ds[i]:
        ds_count[-1] += 1
    else:
        ds_set.append(ds[i])
        ds_count.append(1)

        
for i in range(q):
    t, d = map(int, input().split())
    if not ds:
        print(-1)
        continue


    index = bisect_left(ds_set, d)
    if t == 1:
        if d >= ds_set[-1]:
            print(-1)
            continue

        # print(index)

        if ds_set[index] == d:
            index += 1

    else:
        if ds_set[0] > d:
            print(-1)
            continue
        # print(index)

        if index >= len(ds_set):
            index -= 1

        if ds_set[index] > d:
            index -= 1

    print(ds_set[index])

    if ds_count[index] > 1:
        ds_count[index] -= 1
    else:
        ds_count.pop(index)
        ds_set.pop(index)


