import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n, m, y, x, k = list(map(int, input().split()))
board = [list(map(int, input().split())) for _ in range(n)]
cmds = list(map(int, input().split()))


dy = [0, 0, 0, -1, 1]
dx = [0, 1, -1, 0, 0]
dice = [0] * 7


def rotate_dice(dir):
    if dir == 1:
        tmp = dice[4]
        dice[4] = dice[6]
        dice[6] = dice[3]
        dice[3] = dice[1]
        dice[1] = tmp
    if dir == 2:
        tmp = dice[3]
        dice[3] = dice[6]
        dice[6] = dice[4]
        dice[4] = dice[1]
        dice[1] = tmp
    if dir == 3:
        tmp = dice[5]
        dice[5] = dice[6]
        dice[6] = dice[2]
        dice[2] = dice[1]
        dice[1] = tmp
    if dir == 4:
        tmp = dice[2]
        dice[2] = dice[6]
        dice[6] = dice[5]
        dice[5] = dice[1]
        dice[1] = tmp


for cmd in cmds:
    nx, ny = x + dx[cmd], y + dy[cmd]

    if 0 > nx or nx >= m or 0 > ny or ny >= n:
        continue

    rotate_dice(cmd)

    if board[ny][nx] == 0:
        board[ny][nx] = dice[6]
    else:
        dice[6] = board[ny][nx]
        board[ny][nx] = 0

    x, y = nx, ny
    print(dice[1])
