# Solution to Volatile Kite by Ava Pun
# Key concepts: geometry

import sys
import math

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N = int(data_next())
arr = list(zip(map(int, data[1::2]), map(int, data[2::2])))

def cross(x1, y1, x2, y2):
    return x1 * y2 - x2 * y1

def dist(x, y):
    return math.sqrt(x * x + y * y)

ans = 4000000000.0
for i in range(N):
    x1, y1 = arr[i - 1]
    x2, y2 = arr[i]
    x1 -= arr[i - 2][0]
    x2 -= arr[i - 2][0]
    y1 -= arr[i - 2][1]
    y2 -= arr[i - 2][1]
    ans = min(ans, abs(cross(x1, y1, x2, y2) / dist(x2, y2) / 2))
print(ans)
