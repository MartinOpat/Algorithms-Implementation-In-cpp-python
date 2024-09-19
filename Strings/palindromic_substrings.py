def find_palindromes(s):
    palindromes = set()
    N = len(s)

    for i in range(N):
        # Odd-length palindromes
        left, right = i, i
        while left >= 0 and right < N and s[left] == s[right]:
            if right - left + 1 >= 2:
                palindromes.add(s[left:right+1])
            left -= 1
            right += 1

        # Even-length palindromes
        left, right = i, i+1
        while left >= 0 and right < N and s[left] == s[right]:
            if right - left + 1 >= 2:
                palindromes.add(s[left:right+1])
            left -= 1
            right += 1

    return sorted(palindromes)

try:
    while True:
        line = input()
        if not line:
            continue
        s = line.strip()
        palindromic_substrings = find_palindromes(s)
        for palindrome in palindromic_substrings:
            print(palindrome)
        print()
except EOFError:
    pass
