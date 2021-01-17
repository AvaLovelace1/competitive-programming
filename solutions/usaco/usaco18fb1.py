# Solution to USACO '18 February B1 - Teleportation by Ava Pun
# Key concepts: implementation

import sys

inp = sys.stdin
out = sys.stdout

inp = open("teleport.in", "r")
out = open("teleport.out", "w")

data = inp.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]


a, b, x, y = int(data_next()), int(data_next()), int(data_next()), int(data_next())

ans = min(abs(a - b), abs(a - x) + abs(b - y), abs(a - y) + abs(b - x))

out.write(str(ans) + '\n')

