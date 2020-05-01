# Solution to Permutations by Ava Pun
# Key concepts: brute force, combinatorics, implementation

import sys

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
K = int(data_next())

arr = []
for i in range(N):
    arr.append(list(data_next()));

perm = []
for i in range(K):
    perm.append(str(i))

def next_perm():
    global perm, arr
    for i in reversed(range(len(perm) - 1)):
        if perm[i] < perm[i + 1]:
            break
    else:
        return False
    for j in reversed(range(i + 1, len(perm))):
        if perm[i] < perm[j]:
            break
    perm[i], perm[j] = perm[j], perm[i]
    perm[i + 1:] = reversed(perm[i + 1:])
    for k in range(len(arr)):
        arr[k][i], arr[k][j] = arr[k][j], arr[k][i]
        arr[k][i + 1:] = reversed(arr[k][i + 1:])
    return True

ans = 1000000000
while True:
    ans = min(ans, int("".join(max(arr))) - int("".join(min(arr))))
    if (not(next_perm())):
        break

print(ans)
