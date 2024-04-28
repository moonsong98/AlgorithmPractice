import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n = int(input())
arr = list(map(int, input().split()))
ops = list(map(int, input().split()))


def calc(a, b, op):
    if op == 0:
        return a + b
    if op == 1:
        return a - b
    if op == 2:
        return a * b
    if op == 3:
        if a >= 0:
            return a // b
        else:
            a = -a
            ret = a // b
            return -ret


def bt(index, op_seq, ops):
    if index == n - 1:
        ret = arr[0]
        for i in range(n - 1):
            ret = calc(ret, arr[i + 1], op_seq[i])
        return ret, ret

    m, M = int(1e9 + 7), -int(1e9 + 7)

    for i in range(4):
        if ops[i] > 0:
            ops[i] -= 1
            op_seq.append(i)
            m_tmp, M_tmp = bt(index + 1, op_seq, ops)
            m = min(m, m_tmp)
            M = max(M, M_tmp)
            op_seq.pop()
            ops[i] += 1

    return m, M


m, M = bt(0, [], ops)

print(M)
print(m)
