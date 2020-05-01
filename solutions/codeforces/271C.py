# Solution to Secret by Ava Pun
# Key concepts: implementation, greedy algorithms

import sys

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
K = int(data_next())

if N // K < 3:
    print(-1)
else:
    ans = [K] * N
    pos = 1
    for i in range(1, K):
        if i % 2 == 1:
            ans[pos] = ans[pos + 1] = ans[pos + 3] = i
        else:
            ans[pos - 1] = ans[pos + 1] = ans[pos + 2] = i
        pos += 3
    print(*ans)
