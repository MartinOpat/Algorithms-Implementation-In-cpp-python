cc, e, c = map(int, input().split())

D = (e/2+4)**2 - 4*(e+4+c)
b = (e/2+4)

if cc != 4 or D < 0 or e % 2 != 0 or int(D**0.5)**2 != D:
    print("impossible")
    exit()

w2 = int((-b - D**0.5)/(-2))
h2 = int((b - D**0.5)/2)

print(w2, h2) 
