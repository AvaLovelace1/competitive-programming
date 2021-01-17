# Solution to USACO '15 December B2 - Speeding Ticket by Ava Pun
# Key concepts: simulation, implementation

import sys

inp = sys.stdin
out = sys.stdout

inp = open("speeding.in", "r")
out = open("speeding.out", "w")

data = inp.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]


N, M = int(data_next()), int(data_next())

arr1 = []
arr2 = []
for i in range(N):
    arr1.append([int(data_next()), int(data_next())])
for i in range(M):
    arr2.append([int(data_next()), int(data_next())])

ans = 0
tot1 = 0
tot2 = 0
j = 0
for d, s in arr1:
    tot1 += d
    if tot2 > tot1:
        ans = max(ans, arr2[j - 1][1] - s)
    while j < M and tot2 < tot1:
        ans = max(ans, arr2[j][1] - s)
        tot2 += arr2[j][0]
        j += 1

out.write(str(ans) + '\n')
    
