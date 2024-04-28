import sys

input = sys.stdin.readline


def spread(board):
    r, c = len(board), len(board[0])
    diff = [[0 for _ in range(c)] for _ in range(r)]

    dy = [0, -1, 0, 1]
    dx = [1, 0, -1, 0]

    for y in range(r):
        for x in range(c):
            spread_amt = 0
            if board[y][x] > 0:
                for i in range(4):
                    ny, nx = y + dy[i], x + dx[i]
                    if not (0 <= ny and ny < r and 0 <= nx and nx < c):
                        continue
                    if board[ny][nx] == -1:
                        continue
                    diff[ny][nx] += board[y][x] // 5
                    spread_amt += board[y][x] // 5
            diff[y][x] -= spread_amt

    for i in range(r):
        for j in range(c):
            board[i][j] += diff[i][j]


def push(board, cleaner_pos):
    r, c = len(board), len(board[0])

    dy = [0, -1, 0, 1]
    dx = [1, 0, -1, 0]

    # clean 1
    y, x = cleaner_pos[0], 1
    prev_dust = 0
    dir = 0
    while True:
        if y == cleaner_pos[0] and x == 0:
            break
        board[y][x], prev_dust = prev_dust, board[y][x]
        if (
            x + dx[dir] == -1
            or x + dx[dir] == c
            or y + dy[dir] == -1
            or y + dy[dir] == r
        ):
            dir = (dir + 1) % 4
        y, x = y + dy[dir], x + dx[dir]

    # clean 2
    y, x = cleaner_pos[1], 1
    prev_dust = 0
    dir = 0
    while True:
        if y == cleaner_pos[1] and x == 0:
            break
        board[y][x], prev_dust = prev_dust, board[y][x]
        if (
            x + dx[dir] == -1
            or x + dx[dir] == c
            or y + dy[dir] == -1
            or y + dy[dir] == r
        ):
            dir = (dir - 1) % 4
        y, x = y + dy[dir], x + dx[dir]


def solve():
    r, c, t = list(map(int, input().split()))
    board = [list(map(int, input().split())) for _ in range(r)]

    cleaner_pos = [None, None]
    for y in range(r):
        if board[y][0] == -1:
            cleaner_pos = [y, y + 1]
            break

    for _ in range(t):
        spread(board)
        push(board, cleaner_pos)

    ans = 0
    for i in range(r):
        for j in range(c):
            if board[i][j] > 0:
                ans += board[i][j]

    print(ans)


solve()
