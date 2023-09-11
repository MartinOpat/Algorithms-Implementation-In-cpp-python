n = int(input())
ps = [int(x) for x in input().split()]
q = int(input())

ps_sum = sum(ps)
ps_hist = {}
key_offset = 0
for p in ps:
    if p in ps_hist:
        ps_hist[p] += 1
    else:
        ps_hist[p] = 1

for i in range(q):
    instruction = input().split()
    # print(ps_sum, ps_hist, key_offset)

    if instruction[0] == "INFLATION":
        x = int(instruction[1])
        key_offset += x
        ps_sum += x*n
        print(ps_sum)

        # naive (group 1+2)
        # ps = list(map(lambda l: l+x, ps))
        # print(sum(ps))
    else:
        x, y = int(instruction[1]), int(instruction[2])

        if x - key_offset not in ps_hist or ps_hist[x - key_offset] == 0 or x == y:
            print(ps_sum)
            continue

        ps_sum += ps_hist[x-key_offset] * (y - x)
        if y - key_offset in ps_hist:
            ps_hist[y - key_offset] += ps_hist[x - key_offset]
        else:
            ps_hist[y - key_offset] = ps_hist[x - key_offset]
        ps_hist[x - key_offset] = 0

        print(ps_sum)

        # naive (group 1+2)
        # for j in range(n):
        #     if ps[j] == x:
        #         ps[j] = y
        # print(sum(ps))

