# Solution to USACO '16 January B1 - Promotion Counting by Ava Pun
# Key concepts: implementation

import sys

inp = sys.stdin
out = sys.stdout

inp = open("promote.in", "r")
out = open("promote.out", "w")

data = inp.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]


arr = []

for i in range(4):
    arr.append([int(data_next()), int(data_next())])

ans = [0, 0, 0]
for i in reversed(range(1, 4)):
    diff = arr[i][1] - arr[i][0]
    ans[i - 1] = diff
    arr[i - 1][1] += diff

for i in ans:
    out.write(str(i) + '\n')

