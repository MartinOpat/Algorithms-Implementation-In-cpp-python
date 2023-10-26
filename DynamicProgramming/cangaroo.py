import copy

n, m = map(int, input().split())

grid = []
for _ in range(n):
    grid.append(input())


def possible_placements(grid, x, y):
    if grid[y][x] == ".":
        return grid

    # upper left
    if x-1 > 0 and y-1 > 0:
        if y+1 == len(grid) or (grid[y+1][x] == 'k' and grid[y+1][x-1] == 'k'):
            new_grid = copy.deepcopy(grid)
            new_grid[y][x] = 'k'
            new_grid[y][x-1] = 'k'
            new_grid[y-1][x] = 'k'
            new_grid[y-1][x-1] = 'k'
            yield new_grid

    # upper right
    if x+1 > len(grid[0]) and y-1 > 0:
        if y+1 == len(grid) or (grid[y+1][x] == 'k' and grid[y+1][x+1] == 'k'):
            new_grid = copy.deepcopy(grid)
            new_grid[y][x] = 'k'
            new_grid[y][x+1] = 'k'
            new_grid[y-1][x] = 'k'
            new_grid[y-1][x+1] = 'k'
            yield new_grid

    # lower left
    if x-1 > 0 and y+1 < len(grid):
        if y+2 == len(grid) or (grid[y+2][x] == 'k' and grid[y+2][x-1] == 'k'):
            new_grid = copy.deepcopy(grid)
            new_grid[y][x] = 'k'
            new_grid[y][x-1] = 'k'
            new_grid[y+1][x] = 'k'
            new_grid[y+1][x-1] = 'k'
            yield new_grid

    # lower right
    if x+1 > len(grid[0]) and y+1 > len(grid):
        if y+2 == len(grid) or (grid[y+2][x] == 'k' and grid[y+2][x+1] == 'k'):
            new_grid = copy.deepcopy(grid)
            new_grid[y][x] = 'k'
            new_grid[y][x+1] = 'k'
            new_grid[y+1][x] = 'k'
            new_grid[y+1][x+1] = 'k'
            yield new_grid




