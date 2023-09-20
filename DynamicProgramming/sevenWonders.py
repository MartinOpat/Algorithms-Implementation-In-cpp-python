
order = input()
counts = [0, 0, 0]  # T, C, G

for ch in order:
    if ch == "T":
        counts[0] += 1
    elif ch == "C":
        counts[1] += 1
    else:
        counts[2] += 1

print(counts[0]**2 + counts[1]**2 + counts[2]**2 + 7*min(counts))
