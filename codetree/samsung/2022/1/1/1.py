import sys

input = sys.stdin.readline


class Slave:
    def __init__(self, direction, y, x):
        self.direction = direction
        self.y = y
        self.x = x


dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def get_master_dir(master_pos, master_dir):
    dir_cnt = 0
    cnt = 0
    goal = 1
    cur_dir = 0

    while master_pos != [0, 0]:
        master_pos = [master_pos[0] + dy[cur_dir], master_pos[1] + dx[cur_dir]]
        master_dir.append(cur_dir)
        cnt += 1
        if cnt == goal:
            dir_cnt += 1
            cnt = 0
            cur_dir = (cur_dir + 1) % 4
        if dir_cnt == 2:
            goal += 1
            dir_cnt = 0


def solve():
    n, m, h, k = list(map(int, input().split()))
    master_pos = [n // 2, n // 2]
    master_dir = []
    master_dir_index = 0
    get_master_dir(master_pos, master_dir)

    tree_board = [[False for _ in range(n)] for _ in range(n)]
    board = [[set() for _ in range(n)] for _ in range(n)]
    # board[master_pos[0]][master_pos[1]] = -1
    slaves = [None]
    ans = 0

    for i in range(1, m+1):
        y, x, d = list(map(int, input().split()))
        y -= 1
        x -= 1
        slaves.append(Slave(d, y, x))
        board[y][x].add(i)

    # print("===========")
    # for i in range(n):
    #     for j in range(n):
    #         print(board[i][j], end = ' ')
    #     print()
    # print("===========")

    for _ in range(h):
        y, x = list(map(int, input().split()))
        y -= 1
        x -= 1
        tree_board[y][x] = True

    # print("===========")
    # for i in range(n):
    #     for j in range(n):
    #         print(tree_board[i][j], end = ' ')
    #     print()
    # print("===========")

    for turn in range(1, k + 1):
        moved_slaves = []
        # update slaves' poses
        for i in range(-3, 4):
            for j in range(-3, 4):
                if abs(i) + abs(j) > 3:
                    continue
                if not (0 <= master_pos[0] + i < n and 0 <= master_pos[1] + j < n):
                    continue
                if len(board[master_pos[0] + i][master_pos[1] + j]) == 0:
                    continue

                tmp_remove = []
                for slave_num in board[master_pos[0] + i][master_pos[1] + j]:
                    ny, nx = master_pos[0] + i + dy[slaves[slave_num].direction], master_pos[1] + j + dx[
                        slaves[slave_num].direction]
                    if not (0 <= ny < n and 0 <= nx < n):
                        slaves[slave_num].direction = (slaves[slave_num].direction + 2) % 4
                        ny, nx = master_pos[0] + i + dy[slaves[slave_num].direction], master_pos[1] + j + dx[
                            slaves[slave_num].direction]
                    if [ny, nx] != master_pos:
                        slaves[slave_num].y, slaves[slave_num].x = ny, nx
                        # board[master_pos[0]+i][master_pos[1]+j].remove(slave_num)
                        tmp_remove.append(slave_num)
                        moved_slaves.append(slave_num)
                for el in tmp_remove:
                    board[master_pos[0] + i][master_pos[1] + j].remove(el)

        # Move slaves
        for el in moved_slaves:
            board[slaves[el].y][slaves[el].x].add(el)

        # for i in range(n):
        #     for j in range(n):
        #         print(board[i][j], end=' ')
        #     print()
        # print("===========")

        # Move master:
        master_next_move = master_dir[master_dir_index]
        master_dir_index += 1
        if master_dir_index == n*n-1:
            master_dir_index = 0
            master_dir = master_dir[::-1]
            for i, el in enumerate(master_dir):
                master_dir[i] = (el + 2) % 4
        master_looking = master_dir[master_dir_index]
        master_pos = [master_pos[0] + dy[master_next_move], master_pos[1] + dx[master_next_move]]

        killed = 0
        for i in range(3):
            y, x = master_pos[0] + i * dy[master_looking], master_pos[1] + i * dx[master_looking]
            if not (0 <= y < n and 0 <= x < n):
                continue
            if tree_board[y][x]:
                continue
            if len(board[y][x]) > 0:
                killed += len(board[y][x])
                board[y][x] = set()

        ans += killed * turn

    print(ans)
    # print("ANS:", ans)
    #
    # for i in range(n):
    #     for j in range(n):
    #         print(board[i][j], end = ' ')
    #     print()
    # print("===========")
    # print(master_pos, master_looking)
    # print(master_dir, master_dir_index)


solve()
