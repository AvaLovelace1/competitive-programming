# Solution to USACO '19 January B1 - Shell Game by Ava Pun
# Key concepts: simulation

import sys

inp = sys.stdin
out = sys.stdout

inp = open("shell.in", "r")
out = open("shell.out", "w")

data = inp.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
arr = []
for i in range(N):
    arr.append([int(data_next()), int(data_next()), int(data_next())])

max_ans = 0
for i in range(1,4):
    loc = i
    ans = 0
    for i in range(N):
        if arr[i][0] == loc:
            loc = arr[i][1]
        elif arr[i][1] == loc:
            loc = arr[i][0]
        ans += arr[i][2] == loc
    max_ans = max(ans, max_ans)
out.write(str(max_ans) + '\n')
