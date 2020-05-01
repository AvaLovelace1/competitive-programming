# Solution to News About Credit by Ava Pun
# Key concepts: implementation, greedy algorithms, two pointers

import sys

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
arr = list(zip(map(int, data[2:]), range(2, N + 1)))
arr.sort()
arr.append((int(data[1]), 1))
arr.reverse()

j = 1
good = True
ans = []
for i in range(0, N):
    if j > i:
        for k in range(arr[i][0]):
            if j >= N:
                break
            ans.append((arr[i][1], arr[j][1]))
            j += 1
    else:
        good = False
        break

if good:
    print(len(ans))
    for x in ans:
        print(x[0], x[1])
else:
    print(-1)
