# Solution to USACO '18 December B1 - Mixing Milk by Ava Pun
# Key concepts: simulation

import sys

inp = sys.stdin
out = sys.stdout

inp = open("mixmilk.in", "r")
out = open("mixmilk.out", "w")

data = inp.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

arr = []
for i in range(3):
    arr.append([int(data_next()), int(data_next())])

for i in range(100):
    b1 = i % 3
    b2 = (i + 1) % 3
    amt = min(arr[b2][0] - arr[b2][1], arr[b1][1])
    arr[b1][1] -= amt
    arr[b2][1] += amt

for i in range(3):
    out.write(str(arr[i][1]) + '\n')
