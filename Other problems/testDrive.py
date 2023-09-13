a, b, c = map(int, input().split())

info = (c-b) / (b-a)

if info < 0:
    print("turned")
elif info < 1:
    print("braked")
elif info == 1:
    print("cruised")
else:
    print("accelerated")
