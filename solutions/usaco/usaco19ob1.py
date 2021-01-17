# Solution to USACO '19 Open B1 - Bucket Brigade by Ava Pun
# Key concepts: implementation

import sys

inp = sys.stdin
out = sys.stdout

inp = open("buckets.in", "r")
out = open("buckets.out", "w")

data = inp.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]


N = len(data)
M = len(data[0])

for i in range(N):
    for j in range(M):
        if data[i][j] == 'B':
            barn = [i, j]
        elif data[i][j] == 'L':
            lake = [i, j]
        elif data[i][j] == 'R':
            rock = [i, j]

ans = abs(barn[0] - lake[0]) + abs(barn[1] - lake[1]) - 1

for i, j in [[0, 1], [1, 0]]:
    if barn[i] == lake[i] and lake[i] == rock[i] and rock[j] > min(barn[j], lake[j]) and rock[j] < max(barn[j], lake[j]):
        ans += 2

out.write(str(ans) + '\n')

