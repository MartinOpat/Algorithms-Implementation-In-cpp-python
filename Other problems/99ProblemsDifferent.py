n = input()


if int(n) < 149:
    print(99)
    exit()


if int(n[-2:]) == 49:
    print(n[:-2] + "99")
    exit()


if int(n[-2]) < 5:
    n = str(int(n) - 100)
    print(n[:-2] + "99")
else:
    print(n[:-2] + "99")



