import sys

input = sys.stdin.readline


def check(user_num, dir, users, damage, board, checked):
    checked[user_num] = True

    l = len(board) - 1
    cur_y, cur_x, h, w, _ = users[user_num]

    can_move = True

    if dir == 0:
        if cur_y == 1:
            return False

        for x in range(cur_x, cur_x + w):
            if board[cur_y - 1][x] == -1:
                return False
            if board[cur_y - 1][x] > 0 and not checked[board[cur_y - 1][x]]:
                can_move = can_move & check(board[cur_y - 1][x], dir, users, damage, board, checked)

    if dir == 1:
        if cur_x + w - 1 == l:
            return False

        for y in range(cur_y, cur_y + h):
            if board[y][cur_x + w] == -1:
                return False
            if board[y][cur_x + w] > 0 and not checked[board[y][cur_x + w]]:
                can_move = can_move & check(board[y][cur_x + w], dir, users, damage, board, checked)

    if dir == 2:
        if cur_y + h - 1 == l:
            return False

        for x in range(cur_x, cur_x + w):
            if board[cur_y + h][x] == -1:
                return False
            if board[cur_y + h][x] > 0 and not checked[board[cur_y + h][x]]:
                can_move = can_move & check(board[cur_y + h][x], dir, users, damage, board, checked)

    if dir == 3:
        if cur_x == 1:
            return False

        for y in range(cur_y, cur_y + h):
            if board[y][cur_x - 1] == -1:
                return False
            if board[y][cur_x - 1] > 0 and not checked[board[y][cur_x - 1]]:
                can_move = can_move & check(board[y][cur_x - 1], dir, users, damage, board, checked)

    return can_move


def move(user_num, dir, users, damage, board, moved, is_init):
    cur_y, cur_x, h, w, k = users[user_num]

    if dir == 0:
        for x in range(cur_x, cur_x + w):
            if board[cur_y - 1][x] > 0 and not moved[board[cur_y - 1][x]]:
                move(board[cur_y - 1][x], dir, users, damage, board, moved, False)

    if dir == 1:
        for y in range(cur_y, cur_y + h):
            if board[y][cur_x + w] > 0 and not moved[board[y][cur_x + w]]:
                move(board[y][cur_x + w], dir, users, damage, board, moved, False)

    if dir == 2:
        for x in range(cur_x, cur_x + w):
            if board[cur_y + h][x] > 0 and not moved[board[cur_y + h][x]]:
                move(board[cur_y + h][x], dir, users, damage, board, moved, False)

    if dir == 3:
        for y in range(cur_y, cur_y + h):
            if board[y][cur_x - 1] > 0 and not moved[board[y][cur_x - 1]]:
                move(board[y][cur_x - 1], dir, users, damage, board, moved, False)

    damage_got = 0
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    ny, nx = cur_y + dy[dir], cur_x + dx[dir]

    if not is_init:
        damage_got = damage[ny + h - 1][nx + w - 1] - damage[ny - 1][nx + w - 1] - damage[ny + h - 1][nx - 1] + \
                     damage[ny - 1][nx - 1]

    for y in range(cur_y, cur_y + h):
        for x in range(cur_x, cur_x + w):
            board[y][x] = 0
    if damage_got >= k:
        users[user_num][4] = 0
    else:
        board[ny][nx] = board[cur_y][cur_x]
        for y in range(ny, ny + h):
            for x in range(nx, nx + w):
                board[y][x] = user_num

        users[user_num][4] = users[user_num][4] - damage_got
        users[user_num][0], users[user_num][1] = ny, nx
    moved[user_num] = True


def solve():
    l, n, q = list(map(int, input().split()))
    board = [[0 for _ in range(l + 1)]] + [[0] + list(map(int, input().split())) for _ in range(l)]
    damage = [[0 for _ in range(l + 1)] for _ in range(l + 1)]
    for i in range(1, l + 1):
        for j in range(1, l + 1):
            damage[i][j] = int(board[i][j] == 1)

            # hole => 0, wall => -1
            if board[i][j] == 1:
                board[i][j] = 0
            elif board[i][j] == 2:
                board[i][j] = -1

            damage[i][j] += damage[i - 1][j] + damage[i][j - 1] - damage[i - 1][j - 1]

    users = [None] + [list(map(int, input().split())) for _ in range(n)]
    init_hp = [0] + [users[i][4] for i in range(1, len(users))]

    for u in range(1, len(users)):
        r, c, h, w, _ = users[u]
        for i in range(r, r + h):
            for j in range(c, c + w):
                board[i][j] = u

    for _ in range(q):
        user_num, dir = list(map(int, input().split()))
        if users[user_num][4] > 0:
            can_move = check(user_num, dir, users, damage, board, [False for _ in range(n + 1)])
            if can_move:
                move(user_num, dir, users, damage, board, [False for _ in range(n + 1)], True)

    ans = 0
    for i in range(1, n + 1):
        if users[i][4] > 0:
            ans += init_hp[i] - users[i][4]
    print(ans)


solve()
