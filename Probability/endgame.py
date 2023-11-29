import random


def exists_move(x1, y1, x2, y2):
    global moves

    if (x2-x1, y2-y1) in moves: return True

    for dx, dy in moves:
        if x1 + dx <= 0 or y1 + dy <= 0 or x1+dx > n or y1+dy > n: continue
        if (x2-x1-dx, y2-y1-dy) in moves: return True

    return False


n = int(input())

ax, ay = map(int, input().split())
bx, by = map(int, input().split())
moves = set(tuple(map(int, input().split())) for _ in range(n))
moves.add((0, 0))

if exists_move(ax, ay, bx, by):
    print("Alice wins")
    exit()

npos = 30
for _ in range(npos):
    x = random.randint(1, n)
    y = random.randint(1, n)

    if not exists_move(bx, by, x, y):
        print(f"tie {x} {y}")
        exit()

print("Bob wins")


