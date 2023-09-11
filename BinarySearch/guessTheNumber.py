lower = 1
upper = 1000
ans = ""

while ans != "correct":
    mid = lower + (upper - lower) // 2
    print(mid, flush=True)
    ans = input()

    if ans == "lower":
        upper = mid - 1
    else:
        lower = mid + 1
