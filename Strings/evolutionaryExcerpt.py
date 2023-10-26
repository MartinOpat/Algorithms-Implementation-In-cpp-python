n = int(input())
s1 = input()
s2 = input()

def lcs(X, Y, m, n):
    L = [[0 for _ in range((n+1)//2+1)] for __ in range((m+1)//2+1)]
    i2, j2 = -1, -1
 
    # Following steps build L[m+1][n+1] in bottom up fashion. Note
    # that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif X[i-1] == Y[j-1]:
                L[i][j] = L[i-1][j-1] + 1
            else:
                L[i][j] = max(L[i-1][j], L[i][j-1])

            if L[i][j] >= (n+1)//2:
                i2 = i+1
                j2 = j+1
                break
        else:
            continue
        break


 
        # Create a string variable to store the lcs string
    lcs = ""
 
    # Start from the right-most-bottom-most corner and
    # one by one store characters in lcs[]
    if i2 == -1:
        i2 = m
        j2 = n

    while i2 > 0 and j2 > 0:
        # If current character in X[] and Y are same, then
        # current character is part of LCS
        if X[i2-1] == Y[j2-1]:
            lcs += X[i2-1]
            i2 -= 1
            j2 -= 1
 
        # If not same, then find the larger of two and
        # go in the direction of larger value
        elif L[i2-1][j2] > L[i2][j2-1]:
            i2 -= 1
        else:
            j2 -= 1
 
    # We traversed the table in reverse order
    # LCS is the reverse of what we got
    lcs = lcs[::-1]
    return lcs
    # print("LCS of " + X + " and " + Y + " is " + lcs)


print(lcs(s1, s2, n, n))
