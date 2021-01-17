# Solution to USACO '20 January B1 - Word Processor by Ava Pun
# Key concepts: implementation

import sys

inp = sys.stdin
out = sys.stdout

inp = open("word.in", "r")
out = open("word.out", "w")

data = inp.read().split()
data_ptr = 0

def data_next():
    global data_ptr, data
    data_ptr += 1
    return data[data_ptr - 1]

N, K = int(data_next()), int(data_next())

tot = 0;
for i in range(N):
    word = data_next()
    if tot + len(word) > K:
        out.write('\n')
        tot = len(word)
    else:
        if (tot != 0):
            out.write(' ')
        tot += len(word)
    out.write(word)
out.write('\n')
