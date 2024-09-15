m = int(input())

# 4 ? 4 ? 4 ? 4 = n

mul = lambda x, y: x * y
div = lambda x, y: x // y
add = lambda x, y: x + y
sub = lambda x, y: x - y

conversion1 = {
    mul: '*',
    div: '//',
    add: '+',
    sub: '-'
}

conversion2 = {
    mul: '*',
    div: '/',
    add: '+',
    sub: '-'
}

vals = dict()

for operator  in [mul, div, add, sub]:
    for operator2 in [mul, div, add, sub]:
        for operator3 in [mul, div, add, sub]:
            val = eval(f"4 {conversion1[operator]} 4 {conversion1[operator2]} 4 {conversion1[operator3]} 4")
            if val not in vals:
                vals[val] = (conversion2[operator], conversion2[operator2], conversion2[operator3])

            

for _ in range(m):
    n = int(input())

    if n in vals:
        print(f"4 {vals[n][0]} 4 {vals[n][1]} 4 {vals[n][2]} 4 = {n}")
    else:
        print("no solution")
