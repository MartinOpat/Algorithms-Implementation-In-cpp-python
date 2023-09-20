
seen = {}


def solve(start, end, boxes):
    tup = (start, end, boxes)
    if boxes == 1 or start >= end - 1:
        val = (start + end) * (end - start + 1) / 2
        seen[tup] = val
        return val
    lowest = 100000000000000000

    for x in range(end - 1, start, -1):
        firstup = (x + 1, end, boxes)
        first = seen[firstup] if firstup in seen else solve(x + 1, end, boxes)
        if first >= lowest:
            break
        secondtup = (start, x - 1, boxes - 1)
        second = seen[secondtup] if secondtup in seen else solve(start, x - 1, boxes - 1)
        if second >= lowest:
            break
        lowest = min(lowest, x + max(first, second))
    seen[tup] = lowest
    return lowest


n = int(input())

for _ in range(n):
    k, m = map(int, input().split())
    print(int(solve(0, m, k)))





