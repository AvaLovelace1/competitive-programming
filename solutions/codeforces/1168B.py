# Solution to Good Triple by Ava Pun
# Key concepts: brute force

import sys
import math

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

S = data[0]
N = len(S)

ans = 0
if N >= 9:
    ans += (N - 8) * (N - 7) // 2
for l in range(3, 9):
    for i in range(N - l + 1):
        j = i + l - 1
        for start in range(i, j - 1):
            k = 1
            found = False
            while start + 2 * k <= j:
                if S[start] == S[start + k] and S[start + k] == S[start + 2 * k]:
                    found = True
                    break
                k += 1
            if found:
                ans += 1
                break
print(ans)
