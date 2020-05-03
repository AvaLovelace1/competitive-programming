# Solution to Shopping by Ava Pun
# Key concepts: implementation, brute force

import sys

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
M = int(data_next())
K = int(data_next())
arr = []
for i in range(K):
    arr.append(int(data_next()))

ans = 0
for i in range(N):
    for j in range(M):
        item = int(data_next())
        idx = arr.index(item)
        arr = [item] + arr[0:idx] + arr[idx + 1:]
        ans += idx + 1
print(ans)
