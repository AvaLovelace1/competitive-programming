  
# Solution to Union of Doubly Linked Lists by Ava Pun
# Key concepts: implementation, graph theory

import sys

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
pre = [0] + list(map(int, data[1::2]))
nxt = [0] + list(map(int, data[2::2]))
vis = [False] * (N + 1)

def find_last(u, nxt):
    while nxt[u] != 0:
        u = nxt[u]
        vis[u] = True
    return u

pre_last = -1
for i in range(1, N + 1):
    if not(vis[i]):
        vis[i] = True
        first = find_last(i, pre)
        last = find_last(i, nxt)
        if pre_last != -1:
            nxt[pre_last] = first
            pre[first] = pre_last
        pre_last = last

for i in range(1, N + 1):
    print(pre[i], nxt[i])
