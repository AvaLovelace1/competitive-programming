# Solution to USACO '19 February B3 - Measuring Traffic by Ava Pun
# Key concepts: implementation, simulation

import sys

inp = sys.stdin
out = sys.stdout

inp = open("traffic.in", "r")
out = open("traffic.out", "w")

data = inp.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]


N = int(data_next())
arr = []
for i in range(N):
    arr.append([data_next(), int(data_next()), int(data_next())])

def solve(ans, t, a, b):
    if t == 'on':
        ans[0] += a
        ans[1] += b
    elif t == 'off':
        ans[0] = max(0, ans[0] - b)
        ans[1] = max(0, ans[1] - a)
    elif t == 'none':
        ans[0] = max(ans[0], a)
        ans[1] = min(ans[1], b)

ans = [0, 1000000000]
for t, a, b in reversed(arr):
    if t == 'on':
        t = 'off'
    elif t == 'off':
        t = 'on'
    solve(ans, t, a, b)
out.write(str(ans[0]) + ' ' + str(ans[1]) + '\n')

ans = [0, 1000000000]
for t, a, b in arr:
    solve(ans, t, a, b)
out.write(str(ans[0]) + ' ' + str(ans[1]) + '\n')
