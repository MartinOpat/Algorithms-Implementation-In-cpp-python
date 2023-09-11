cpr = input()

s = 0
m = [4, 3, 2, 7, 6, 5, 4, 3, 2, 1]
i = 0
for d in cpr:
    if d == "-":
        continue

    s += int(d)*m[i]
    i += 1

print(1 if s % 11 == 0 else 0)