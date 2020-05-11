# Solution to Binary Palindromes by Ava Pun
# Key concepts: greedy algorithms

import sys

data = sys.stdin.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

Q = int(data_next())

for test in range(Q):
    N = int(data_next())
    zero_cnt = 0
    one_cnt = 0
    odd_length = False
    for i in range(N):
        string = data_next()
        if len(string) % 2 == 1:
            odd_length = True
        for c in string:
            if c == "0":
                zero_cnt += 1
            else:
                one_cnt += 1
    if odd_length:
        print(N)
    elif zero_cnt % 2 == 0 and one_cnt % 2 == 0:
        print(N)
    else:
        print(N - 1)
