import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

board = [[0] * 101 for _ in range(101)]

dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def draw_dragon_reverse(y, x, d, g):
    if g == 0:
        ny, nx = y + dy[d], x + dx[d]
        board[y][x] = 1
        board[ny][nx] = 1
        return (ny, nx, d)

    ey, ex, ed = draw_dragon(y, x, d, g - 1)
    nd = (ed - 1) % 4
    ey, ex, ed = draw_dragon_reverse(ey, ex, nd, g - 1)
    return ey, ex, ed


def draw_dragon(y, x, d, g):
    if g == 0:
        ny, nx = y + dy[d], x + dx[d]
        board[y][x] = 1
        board[ny][nx] = 1
        return (ny, nx, d)

    ey, ex, ed = draw_dragon(y, x, d, g - 1)
    nd = (ed + 1) % 4
    ey, ex, ed = draw_dragon_reverse(ey, ex, nd, g - 1)
    return ey, ex, ed


n = int(input())
for _ in range(n):
    x, y, d, g = list(map(int, input().split()))
    ey, ex, ed = draw_dragon(y, x, d, g)

cnt = 0
for i in range(100):
    for j in range(100):
        if board[i][j] and board[i][j + 1] and board[i + 1][j] and board[i + 1][j + 1]:
            cnt += 1

print(cnt)
