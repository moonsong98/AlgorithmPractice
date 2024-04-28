import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n, m = list(map(int, input().split()))
board = [list(input().strip()) for _ in range(n)]


def move(dir, blue_pos, red_pos):
    global board
    state = -1
    new_blue_pos = [-1, -1]
    new_red_pos = [-1, -1]
    poses = [blue_pos, red_pos]
    if dir == "u":
        if blue_pos[0] > red_pos[0]:
            poses = [red_pos, blue_pos]

        for pos in poses:
            ball = board[pos[0]][pos[1]]
            next_pos = pos[0]
            board[pos[0]][pos[1]] = "."
            for k in range(pos[0] - 1, -1, -1):
                if board[k][pos[1]] == "O":
                    if ball == "B":
                        state = 0
                    if ball == "R" and state == -1:
                        state = 1
                    next_pos = -1
                    break
                if board[k][pos[1]] != ".":
                    break
                next_pos = k
            if next_pos > -1:
                board[next_pos][pos[1]] = ball
                if ball == "B":
                    new_blue_pos = [next_pos, pos[1]]
                else:
                    new_red_pos = [next_pos, pos[1]]
    if dir == "d":
        if blue_pos[0] < red_pos[0]:
            poses = [red_pos, blue_pos]
        for pos in poses:
            ball = board[pos[0]][pos[1]]
            next_pos = pos[0]
            board[pos[0]][pos[1]] = "."
            for k in range(pos[0] + 1, n):
                if board[k][pos[1]] == "O":
                    if ball == "B":
                        state = 0
                    if ball == "R" and state == -1:
                        state = 1
                    next_pos = -1
                    break
                if board[k][pos[1]] != ".":
                    break
                next_pos = k
            if next_pos > -1:
                board[next_pos][pos[1]] = ball
                if ball == "B":
                    new_blue_pos = [next_pos, pos[1]]
                else:
                    new_red_pos = [next_pos, pos[1]]
    if dir == "r":
        if blue_pos[1] < red_pos[1]:
            poses = [red_pos, blue_pos]
        for pos in poses:
            ball = board[pos[0]][pos[1]]
            next_pos = pos[1]
            board[pos[0]][pos[1]] = "."
            for k in range(pos[1] + 1, m):
                if board[pos[0]][k] == "O":
                    if ball == "B":
                        state = 0
                    if ball == "R" and state == -1:
                        state = 1
                    next_pos = -1
                    break
                if board[pos[0]][k] != ".":
                    break
                next_pos = k
            if next_pos > -1:
                board[pos[0]][next_pos] = ball
                if ball == "B":
                    new_blue_pos = [pos[0], next_pos]
                else:
                    new_red_pos = [pos[0], next_pos]
    if dir == "l":
        if blue_pos[1] > red_pos[1]:
            poses = [red_pos, blue_pos]
        for pos in poses:
            ball = board[pos[0]][pos[1]]
            next_pos = pos[1]
            board[pos[0]][pos[1]] = "."
            for k in range(pos[1] - 1, -1, -1):
                if board[pos[0]][k] == "O":
                    if ball == "B":
                        state = 0
                    if ball == "R" and state == -1:
                        state = 1
                    next_pos = -1
                    break
                if board[pos[0]][k] != ".":
                    break
                next_pos = k
            if next_pos > -1:
                board[pos[0]][next_pos] = ball
                if ball == "B":
                    new_blue_pos = [pos[0], next_pos]
                else:
                    new_red_pos = [pos[0], next_pos]
    return state, new_blue_pos, new_red_pos


def find_original():
    blue_pos, red_pos = None, None

    for i in range(n):
        for j in range(m):
            if board[i][j] == "B":
                blue_pos = (i, j)
            elif board[i][j] == "R":
                red_pos = (i, j)

    return blue_pos, red_pos


def rollback(blue_pos, red_pos, new_blue_pos, new_red_pos):
    if new_blue_pos[0] != -1 and new_blue_pos[1] != -1:
        board[new_blue_pos[0]][new_blue_pos[1]] = "."
    if new_red_pos[0] != -1 and new_red_pos[1] != -1:
        board[new_red_pos[0]][new_red_pos[1]] = "."

    board[blue_pos[0]][blue_pos[1]] = "B"
    board[red_pos[0]][red_pos[1]] = "R"


def solve(cnt, blue_pos, red_pos):
    if cnt == 11:
        return -1

    ret = -1

    for dir in ["r", "d", "l", "u"]:
        state, new_blue_pos, new_red_pos = move(dir, blue_pos, red_pos)

        if state == 1:
            ret = cnt
        elif state == -1:
            poss_val = solve(cnt + 1, new_blue_pos, new_red_pos)
            if ret == -1 or poss_val > -1 and poss_val < ret:
                ret = poss_val

        rollback(blue_pos, red_pos, new_blue_pos, new_red_pos)

    return ret


blue_pos, red_pos = find_original()

print(solve(1, blue_pos, red_pos))
