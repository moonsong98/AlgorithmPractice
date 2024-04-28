import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
memo = [-1] * (11)


def move(dir, board):
    if dir == "u":
        for i in range(n):
            next_pos = 0
            for j in range(0, n - 1):
                if board[j][i] == 0:
                    continue
                if board[j][i] == board[j + 1][i]:
                    board[next_pos][i] = board[j][i] * 2
                else:
                    next_pos += 1

                pass
            new_line = []
            final_line = []
            for j in range(n):
                if board[j][i] > 0:
                    new_line.append(board[j][i])
            j = 0
            while j < len(new_line):
                if j + 1 < len(new_line) and new_line[j] == new_line[j + 1]:
                    final_line.append(new_line[j] * 2)
                    j += 2
                else:
                    final_line.append(new_line[j])
                    j += 1
            final_line += [0] * (n - len(final_line))
            for j in range(n):
                board[j][i] = final_line[j]
    if dir == "d":
        for i in range(n):
            new_line = []
            final_line = []
            for j in range(n):
                if board[j][i] > 0:
                    new_line.append(board[j][i])
            j = len(new_line) - 1
            while j >= 0:
                if j - 1 >= 0 and new_line[j] == new_line[j - 1]:
                    final_line.append(new_line[j] * 2)
                    j -= 2
                else:
                    final_line.append(new_line[j])
                    j -= 1
            final_line += [0] * (n - len(final_line))
            for j in range(n):
                board[j][i] = final_line[n - j - 1]
    if dir == "r":
        for i in range(n):
            new_line = []
            final_line = []
            for j in range(n):
                if board[i][j] > 0:
                    new_line.append(board[i][j])

            j = len(new_line) - 1
            while j >= 0:
                if j - 1 >= 0 and new_line[j] == new_line[j - 1]:
                    final_line.append(new_line[j] * 2)
                    j -= 2
                else:
                    final_line.append(new_line[j])
                    j -= 1
            final_line += [0] * (n - len(final_line))
            for j in range(n):
                board[i][j] = final_line[n - j - 1]
    if dir == "l":
        for i in range(n):
            new_line = []
            final_line = []
            for j in range(n):
                if board[i][j] > 0:
                    new_line.append(board[i][j])
            j = 0
            while j < len(new_line):
                if j + 1 < len(new_line) and new_line[j] == new_line[j + 1]:
                    final_line.append(new_line[j] * 2)
                    j += 2
                else:
                    final_line.append(new_line[j])
                    j += 1
            final_line += [0] * (n - len(final_line))
            for j in range(n):
                board[i][j] = final_line[j]


def get_max(board):
    ret = -1
    for i in range(n):
        if ret == -1 or ret < max(board[i]):
            ret = max(board[i])

    return ret


def check(board, cnt):
    for i in range(n):
        for j in range(n):
            if board[i][j] > memo[cnt]:
                return True
    return False


ans = -1


def solve(cnt, board):
    global ans
    global memo
    if cnt == 11:
        max_val = get_max(board)
        if max_val > ans:
            ans = max_val
        tmp = max_val
        for i in range(10, -1, -1):
            memo[i] = tmp
            tmp //= 2
        return

    for dir in ["l", "d", "u", "r"]:
        new_board = [row[:] for row in board]

        if not check(new_board, cnt):
            return

        move(dir, new_board)

        if new_board == board:
            continue

        solve(cnt + 1, new_board)
        del new_board


solve(1, board)
print(memo[10])
