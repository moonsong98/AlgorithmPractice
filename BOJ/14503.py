import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n, m = list(map(int, input().split()))
y, x, d = list(map(int, input().split()))
board = [list(map(int, input().split())) for _ in range(n)]

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def change_dir(d):
    return (d - 1) % 4


ans = 0
while True:
    if board[y][x] == 0:
        board[y][x] = 2
        ans += 1

    moved = False
    for _ in range(4):
        d = change_dir(d)
        nx, ny = x + dx[d], y + dy[d]
        if board[ny][nx] == 0:
            x, y = nx, ny
            moved = True
            break

    if not moved:
        nx, ny = x - dx[d], y - dy[d]
        if board[ny][nx] == 1:
            break
        x, y = nx, ny

print(ans)
