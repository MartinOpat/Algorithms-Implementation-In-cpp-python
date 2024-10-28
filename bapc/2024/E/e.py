
n = int(input())

print(f"? {1}", flush=True)
lval = int(input())
print(f"? {n}", flush=True)
rval = int(input())

l = 1
r = n

memoi = {}
# memoi[1] = lval
# memoi[n] = rval

for i in range(48):
    m = (l+r)//2
    print(f"? {m}", flush=True)
    mval = int(input())
    memoi[m] = mval
    if 2*mval == lval + rval:
        print(f"! {1} {m} {n}", flush=True)
        exit()
    elif 2*mval < lval + rval:
        l = m
    else:
        r = m

# while True:
#     if 1 != m and m != n:
#         break
# print(memoi)
ans = list(memoi.keys())[0]

for key in memoi:
    if abs(2*memoi[key]-lval-rval) < abs(2*memoi[ans] -lval-rval):
        ans = key



print(f"! {1} {ans} {n}", flush=True)
