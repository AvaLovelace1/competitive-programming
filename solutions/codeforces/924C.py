# Solution to Riverside Curio by Ava Pun
# Key concepts: greedy algorithms, stack

import sys
from collections import deque

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
tot_lines = 0
ans = 0
st = deque()
for i in range(N):
    n = int(data_next())
    if n >= tot_lines:
        for j in range(n - tot_lines):
            prev_repeat = st.pop()
            ans += i - prev_repeat
        tot_lines = n + 1
    else:
        ans += tot_lines - n - 1
        st.append(i)
print(ans)
