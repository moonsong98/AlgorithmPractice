import sys

input = sys.stdin.readline

n, m, h = list(map(int, input().split()))
board = [[0] * (n + 2) for _ in range(h + 1)]


def print_board():
    for i in range(1, h + 1):
        for j in range(n + 2):
            print(board[i][j], end=" ")
        print()


def check_valid(board):
    for i in range(1, n + 1):
        cur = i
        for hh in range(1, h + 1):
            if board[hh][cur] == 1:
                cur += 1
            elif board[hh][cur - 1] == 1:
                cur -= 1
        if cur != i:
            return False
    return True


ans = 4


def bt(step, last_added):
    global board
    global ans
    valid = check_valid(board)
    if valid:
        ans = min(ans, step)
        return

    if step == 3 or step >= ans:
        return

    y, x = last_added
    for j in range(x, n):
        if board[y][j] == 0 and board[y][j - 1] == 0 and board[y][j + 1] == 0:
            board[y][j] = 1
            bt(step + 1, (y, j + 2))
            board[y][j] = 0
    for i in range(y + 1, h + 1):
        for j in range(1, n):
            if board[i][j] == 0 and board[i][j - 1] == 0 and board[i][j + 1] == 0:
                board[i][j] = 1
                bt(step + 1, (i, j + 2))
                board[i][j] = 0


for _ in range(m):
    a, b = list(map(int, input().split()))
    board[a][b] = 1

bt(0, (1, 1))

print(-1 if ans == 4 else ans)
