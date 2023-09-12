r, y, d, w = map(int, input().split())

bank = [0]
out = 0

for i in range(y):
    bank.append((bank[-1] + d)*(1 + r/100))


bank_out = [w]
for i in range(y):
    bank_out.append(bank_out[-1]/(1 + r/100) + w)

i_break = 0
while bank[-(i_break+1)] > bank_out[i_break]:
    i_break += 1

out += bank[-(i_break+1)] - (bank_out[i_break] - w) + d
out += i_break*w
print(out - d*(y - i_break + 1))
