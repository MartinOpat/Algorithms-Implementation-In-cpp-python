def is_sorted(seq):
        return all(seq[i] <= seq[i+1] for i in range(len(seq)-1))

def make_unsorted(sequence):
    for i, num in enumerate(sequence):
        num_str = str(num)
        for j, digit in enumerate(num_str):
            for k in range(len(num_str) != 1, 10):  # j == 0 \equiv 1, cannot replace first digit with a zero if len > 1
                new_num = int(num_str[:j] + str(k) + num_str[j+1:])
                new_sequence = sequence[:i] + [new_num] + sequence[i+1:]
                if not is_sorted(new_sequence):
                    return new_sequence
    
    return []
    
    
n = int(input())
ans = make_unsorted([int(x) for x in input().split()])
if len(ans) != 0:
    print(*ans)
else:
    print("impossible")
