# Solution to USACO '17 Open B1 - The Lost Cow by Ava Pun
# Key concepts: simulation, implementation

import sys

inp = sys.stdin
out = sys.stdout

inp = open("lostcow.in", "r")
out = open("lostcow.out", "w")

data = inp.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]


x, y = int(data_next()), int(data_next())

dist = 1
pos = x
ans = 0
while True:
    new_pos = x + dist
    if (y >= pos and y <= new_pos) or (y >= new_pos and y <= pos):
        ans += abs(pos - y)
        break
    ans += abs(new_pos - pos)
    dist *= -2
    pos = new_pos

out.write(str(ans) + '\n')

