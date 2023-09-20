
t = int(input())
for _ in range(t):
    m, n = map(int, input().split())

    hashes = {}
    hash_table = [-1]*n
    success = True
    for i in range(m):
        hash1, hash2 = map(int, input().split())
        if not success:
            continue

        hashes[i] = [hash1, hash2]

        if hash_table[hash1] == -1:
            hash_table[hash1] = i
        elif hash_table[hash2] == -1:
            hash_table[hash2] = i
        else:
            cuckoo = i
            hash_current = hash1

            while cuckoo != -1:
                new_cuckoo = hash_table[hash_current]
                hash_table[hash_current] = cuckoo
                hash_current = sum(hashes[new_cuckoo]) - hash_current
                cuckoo = new_cuckoo

                if cuckoo == i and hash_current == hash1:
                    success = False
                    break

    print("successful hashing") if success else print("rehash necessary")
