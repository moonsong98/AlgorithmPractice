import sys

input = sys.stdin.readline

N = int(input())
init = input().strip()
cur = list(init)
seq = []

seq.append("".join(init))
seq.append("".join([str(1 ^ int(x)) for x in cur]))

if N > 1:

    def get_reverse_index(left):
        if left == 0:
            return [0]
        prev = get_reverse_index(left - 1)
        return prev + [left] + prev

    reverse_index_list = get_reverse_index(N - 2)

    for reverse_index in reverse_index_list:
        cur[reverse_index] = str(1 ^ int(cur[reverse_index]))
        s = "".join(cur)
        seq.append(s)
        seq.append("".join([str(1 ^ int(x)) for x in cur]))

for idx in range(1 << N):
    if init == seq[idx]:
        for el in seq[idx:]:
            print(el)
        for el in seq[:idx]:
            print(el)
