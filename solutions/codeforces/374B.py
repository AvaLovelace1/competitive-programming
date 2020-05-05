# Solution to Inna and Nine by Ava Pun
# Key concepts: implementation, greedy algorithms

import sys

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

S = data[0]
N = len(S)

ans = 1
block = 0
for i in range(N):
    if i == N - 1 or int(S[i]) + int(S[i + 1]) != 9:
        if block > 0 and block % 2 == 0:
            ans *= block // 2 + 1
        block = 0
    else:
        block += 1
print(ans)
