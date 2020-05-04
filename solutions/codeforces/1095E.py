# Solution to Almost Regular Bracket Sequence by Ava Pun
# Key concepts: implementation, bracket matching

import sys

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
S = list(data[1])

n_open = S.count('(')
n_closed = N - n_open
if n_open > n_closed:
    S.reverse()
    for i in range(N):
        if S[i] == '(':
            S[i] = ')'
        else:
            S[i] = '('

depth = 0
ans = 0
past_first_neg = False
for i in range(N):
    if S[i] == ')':
        depth -= 1
        if depth < -2:
            ans = 0
            break
        if not(past_first_neg):
            ans += 1
        if depth < 0:
            past_first_neg = True
    else:
        depth += 1
if depth != -2:
    ans = 0
print(ans)
