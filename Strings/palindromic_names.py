s = input()
N = len(s)


best_changes = float("inf")
for i in range(N):

    # Odd-length palindromes
    changes_odd = 0
    left, right = i, i
    while left >= 0 and right < N:
        if s[left] != s[right]:
            changes_odd += 1
        left -= 1
        right += 1

    if left == -1 and right != N:
        changes_odd = float("inf")
    else:
        changes_odd += left+1
    best_changes = min(best_changes, changes_odd)


    # Even-length palindromes
    changes_even = 0
    left, right = i, i+1
    while left >= 0 and right < N:
        if s[left] != s[right]:
            changes_even += 1
        left -= 1
        right += 1

    if left == -1 and right != N:
        changes_even = float("inf")
    else:
        changes_even += left+1

    best_changes = min(best_changes, changes_even)
    # print(i, changes_even, changes_odd, best_changes)
print(best_changes)