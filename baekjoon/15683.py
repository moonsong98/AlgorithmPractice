import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n, m = list(map(int, input().split()))


def color_right(y, x, board):
    for nx in range(x + 1, m):
        if board[y][nx] == 6:
            break
        elif board[y][nx] == 0:
            board[y][nx] = "#"


def color_left(y, x, board):
    for nx in range(x - 1, -1, -1):
        if board[y][nx] == 6:
            break
        elif board[y][nx] == 0:
            board[y][nx] = "#"


def color_up(y, x, board):
    for ny in range(y - 1, -1, -1):
        if board[ny][x] == 6:
            break
        elif board[ny][x] == 0:
            board[ny][x] = "#"


def color_down(y, x, board):
    for ny in range(y + 1, n):
        if board[ny][x] == 6:
            break
        elif board[ny][x] == 0:
            board[ny][x] = "#"


# 0: e, 1: w, 2: s, 3: n
def color_c1(dir, pos, board):
    y, x = pos
    if dir == 0:
        color_right(y, x, board)
    if dir == 1:
        color_left(y, x, board)
    if dir == 2:
        color_down(y, x, board)
    if dir == 3:
        color_up(y, x, board)


# 0: h, 1: v
def color_c2(dir, pos, board):
    y, x = pos
    if dir == 0:
        color_left(y, x, board)
        color_right(y, x, board)
    if dir == 1:
        color_down(y, x, board)
        color_up(y, x, board)


# 0: e, 1: s, 2: w, 3: n
def color_c3(dir, pos, board):
    y, x = pos
    if dir == 0:
        color_right(y, x, board)
        color_up(y, x, board)
    if dir == 1:
        color_down(y, x, board)
        color_right(y, x, board)
    if dir == 2:
        color_left(y, x, board)
        color_down(y, x, board)
    if dir == 3:
        color_up(y, x, board)
        color_left(y, x, board)


# 0: e, 1: s, 2: w, 3: n
def color_c4(dir, pos, board):
    y, x = pos
    if dir == 0:
        color_up(y, x, board)
        color_right(y, x, board)
        color_down(y, x, board)
    if dir == 1:
        color_right(y, x, board)
        color_down(y, x, board)
        color_left(y, x, board)
    if dir == 2:
        color_up(y, x, board)
        color_left(y, x, board)
        color_down(y, x, board)
    if dir == 3:
        color_right(y, x, board)
        color_up(y, x, board)
        color_left(y, x, board)


def color_c5(pos, board):
    y, x = pos
    color_up(y, x, board)
    color_down(y, x, board)
    color_right(y, x, board)
    color_left(y, x, board)


def color(c_num, pos, dir, board):
    if c_num == 1:
        color_c1(dir, pos, board)
    if c_num == 2:
        color_c2(dir, pos, board)
    if c_num == 3:
        color_c3(dir, pos, board)
    if c_num == 4:
        color_c4(dir, pos, board)
    if c_num == 5:
        color_c5(pos, board)


board = [list(map(int, input().split())) for _ in range(n)]

cameras = []
camera_poses = []


for i in range(n):
    for j in range(m):
        if 1 <= board[i][j] and board[i][j] <= 5:
            cameras.append(board[i][j])
            camera_poses.append((i, j))


def bt(seq):
    global ans
    if len(seq) == len(cameras):
        tmp_board = [row[:] for row in board]
        for i in range(len(seq)):
            color(cameras[i], camera_poses[i], seq[i], tmp_board)

        cnt = 0
        for i in range(n):
            for j in range(m):
                if tmp_board[i][j] == 0:
                    cnt += 1

        if ans == -1 or cnt < ans:
            ans = cnt
        return

    camera = cameras[len(seq)]
    if camera == 5:
        seq.append(-1)
        bt(seq)
        seq.pop()
    elif camera == 2:
        for i in range(2):
            seq.append(i)
            bt(seq)
            seq.pop()
    else:
        for i in range(4):
            seq.append(i)
            bt(seq)
            seq.pop()


ans = -1
bt([])
print(ans)
