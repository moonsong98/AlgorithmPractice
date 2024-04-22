import sys
import copy

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

ans = -1


def move(dir, board):
    if dir == "u":
        for i in range(n):
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


def solve(cnt, board):
    if cnt == 6:
        return -1

    ret = -1
    for dir in ["l", "d", "u", "r"]:
        new_board = copy.deepcopy(board)
        move(dir, new_board)
        max_val = get_max(new_board)
        if ret == -1 or ret < max_val:
            ret = max_val
        nxt_val = solve(cnt + 1, new_board)
        if ret == -1 or ret < nxt_val:
            ret = nxt_val
        del new_board
    return ret


print(solve(1, board))
