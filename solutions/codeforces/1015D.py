# Solution to Walking Between Houses by Ava Pun
# Key concepts: greedy algorithms

import sys

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
K = int(data_next())
S = int(data_next())

N -= 1

if (S + K - 1) // K > N or S // K < 1:
    print("NO")
else:
    print("YES")
    quo, rem = S // K, S % K
    pos = 1
    for i in range(1, K + 1):
        pos += (-1 if i % 2 == 0 else 1) * (quo + (1 if i <= rem else 0))
        print(pos, end = "")
        print("\n" if i == K else " ", end = "")
