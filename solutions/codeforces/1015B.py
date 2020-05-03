# Solution to Obtaining the String by Ava Pun
# Key concepts: implementation

import sys

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
S = list(data_next())
T = list(data_next())

moves = 0
ans = []
for i in range(N):
    for j in range(i, N):
        if S[j] == T[i]:
            break
    else:
        moves = -1
        break
    for k in reversed(range(i, j)):
        ans.append(k + 1)
        S[k], S[k + 1] = S[k + 1], S[k]
        moves += 1

print(moves)
if moves > 0:
    print(*ans)
