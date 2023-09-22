

def rotate_matrix(m):
    return [[m[j][i] for j in range(len(m))] for i in range(len(m[0])-1,-1,-1)]


grid = [[int(x) for x in input().split()] for _ in range(4)]
move = int(input())

rots = 0
while rots < move:
    grid = rotate_matrix(grid)
    rots += 1

for i in range(4):
    last_el = -1
    last_el_index = -1

    for j in range(4):
        if grid[i][j] == last_el:
            last_el = -1
            grid[i][last_el_index] = 2*grid[i][j]
            grid[i][j] = 0
        else:
            if grid[i][j] != 0:
                last_el = grid[i][j]
                last_el_index = j

    srtd = False
    while not srtd:
        srtd = True
        for j in range(3):
            if grid[i][j] == 0 and grid[i][j+1] != 0:
                srtd = False
                grid[i][j], grid[i][j+1] = grid[i][j+1], grid[i][j]


while (4 - rots) % 4 > 0:

    grid = rotate_matrix(grid)
    rots += 1

[print(*x) for x in grid]




