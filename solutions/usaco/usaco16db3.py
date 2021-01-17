# Solution to USACO '16 December B3 - The Cow-Signal by Ava Pun
# Key concepts: implementation

import sys

inp = sys.stdin
out = sys.stdout

inp = open("cowsignal.in", "r")
out = open("cowsignal.out", "w")

data = inp.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]


M, N, K = int(data_next()), int(data_next()), int(data_next())

arr = []
for i in range(M):
    arr.append(data_next())

for i in range(M * K):
    for j in range(N * K):
        out.write(arr[i // K][j // K])
    out.write('\n')
