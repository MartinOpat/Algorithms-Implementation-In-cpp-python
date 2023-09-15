n = int(input())
cards = [int(x) for x in input().split()]
# hist = [0] * 10001
#
# for card in cards:
#     hist[card] += 1
#
# better_hist = [[]]
# for i in range(1, len(hist)):
#     if hist[i] == 0:
#         if hist[i-1] != 0:
#             better_hist.append([])
#         continue
#
#     better_hist[-1].append(hist[i])
#
# print(better_hist)
# ans = 0
# for i in range(len(better_hist)):
#     if not better_hist[i]:
#         continue
#     ans += max(better_hist[i])
# print(ans)

cards.sort()
# print(cards)

index = 0  # current card index
turns = 0  # how many turns


while not len(cards) == 0:
    current = cards[index]
    # print("current", current)
    try:
        nextIndex = cards.index(current + 1)
        cards.pop(index)
        index = nextIndex - 1
    except:
        cards.pop(index)
        turns += 1
        index = 0

    # print("cards", cards)
    # print("turns", turns)

print(turns)
