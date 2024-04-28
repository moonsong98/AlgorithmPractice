import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))


def bt(seq, answer, m, h, c):
    if len(seq) == m:
        dist = [-1] * len(h)
        c_pos = []
        for idx in seq:
            c_pos.append(c[idx])
        for y, x in c_pos:
            for i, (yy, xx) in enumerate(h):
                d = abs(yy - y) + abs(xx - x)
                if dist[i] == -1 or dist[i] > d:
                    dist[i] = d
        s = 0
        for el in dist:
            s += el
        if answer[0] == -1 or answer[0] > s:
            answer[0] = s

    start = 0 if len(seq) == 0 else seq[-1] + 1
    for i in range(start, len(c)):
        seq.append(i)
        bt(seq, answer, m, h, c)
        seq.pop()


def solution():
    n, m = list(map(int, input().split()))
    board = [list(map(int, input().split())) for _ in range(n)]

    h, c = [], []

    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                h.append((i, j))
            if board[i][j] == 2:
                c.append((i, j))

    dist = [-1] * len(h)
    for y, x in c:
        for i, (yy, xx) in enumerate(h):
            d = abs(yy - y) + abs(xx - x)
            if dist[i] == -1 or dist[i] > d:
                dist[i] = d

    answer = [-1]
    bt([], answer, m, h, c)
    print(answer[0])


solution()
