

def traverse(root, tree):
    global ans
    # m, d, children = tree[root]

    for ch in tree[root][2]:
        tree[ch].append(root)
        traverse(ch, tree)

    parent = tree[root][3]
    to_move = tree[root][0] - 1

    tree[root][0] -= to_move
    tree[parent][0] += to_move
    ans += abs(to_move)


n = int(input())
while n != 0:
    g = {}
    poss_roots = set([i for i in range(1, n+1)])
    for i in range(n):
        line = [int(x) for x in input().split()]
        v = line[0]
        m = line[1]
        d = line[2]
        if d > 0:
            children = line[3:]
        else:
            children = []

        for ch in children:
            poss_roots.remove(ch)

        g[v] = [m, d, children]

    # print(g)
    root = poss_roots.pop()
    g[root].append(root)
    ans = 0
    traverse(root, g)
    # print(g)

    print(ans)
    n = int(input())
