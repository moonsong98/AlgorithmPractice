import sys
from collections import deque

input = sys.stdin.readline

dx = [0, -1, -1, -1, 0, 1, 1, 1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]


def solve():
    m, t = list(map(int, input().split()))
    pacman_pos = list(map(lambda a: int(a) - 1, input().split()))
    egg_board = [[deque() for _ in range(4)] for _ in range(4)]
    monster_board = [[deque() for _ in range(4)] for _ in range(4)]
    tmp_board = [[deque() for _ in range(4)] for _ in range(4)]
    dead_body = [[-1 for _ in range(4)] for _ in range(4)]  # save dead time

    for _ in range(m):
        y, x, d = list(map(lambda a: int(a) - 1, input().split()))
        monster_board[y][x].append(d)

    # print('=======begining==========')
    # for y in range(4):
    #     for x in range(4):
    #         print(monster_board[y][x], end=' ')
    #     print()
    # print('=================')

    for time in range(1, t + 1):

        # 1. create egg
        for y in range(4):
            for x in range(4):
                for el in monster_board[y][x]:
                    egg_board[y][x].append(el)

        # 2. move monster
        for y in range(4):
            for x in range(4):
                for el in monster_board[y][x]:
                    ny, nx = y + dy[el], x + dx[el]
                    if 0 <= ny < 4 and 0 <= nx < 4 and dead_body[ny][nx] == -1 and pacman_pos != [ny, nx]:
                        tmp_board[ny][nx].append(el)
                        continue

                    moved = False

                    for i in range(8):
                        ny, nx = y + dy[(el + i) % 8], x + dx[(el + i) % 8]
                        if not (0 <= ny < 4 and 0 <= nx < 4 and dead_body[ny][nx] == -1 and pacman_pos != [ny, nx]):
                            continue
                        tmp_board[ny][nx].append((el + i) % 8)
                        moved = True
                        break

                    if not moved:
                        tmp_board[y][x].append(el)

        for y in range(4):
            for x in range(4):
                monster_board[y][x] = tmp_board[y][x].copy()
                tmp_board[y][x] = deque()

        # print('=================')
        # for y in range(4):
        #     for x in range(4):
        #         print(monster_board[y][x], end=' ')
        #     print()
        # print('=================')

        # 3. move pacman
        max_dir_seq = [0, 0, 0]
        path = []
        max_amt = -1
        # print(pacman_pos)
        for dir1 in [0, 2, 4, 6]:
            ny1, nx1 = pacman_pos[0] + dy[dir1], pacman_pos[1] + dx[dir1]
            if not (0 <= ny1 < 4 and 0 <= nx1 < 4):
                continue
            amt1 = len(monster_board[ny1][nx1])
            path.append((ny1, nx1))
            for dir2 in [0, 2, 4, 6]:
                ny2, nx2 = ny1 + dy[dir2], nx1 + dx[dir2]
                if not (0 <= ny2 < 4 and 0 <= nx2 < 4):
                    continue
                if (ny2, nx2) in path:
                    amt2 = 0
                else:
                    amt2 = len(monster_board[ny2][nx2])
                path.append((ny2, nx2))
                for dir3 in [0, 2, 4, 6]:
                    ny3, nx3 = ny2 + dy[dir3], nx2 + dx[dir3]
                    if not (0 <= ny3 < 4 and 0 <= nx3 < 4):
                        continue
                    if (ny3, nx3) in path:
                        amt3 = 0
                    else:
                        amt3 = len(monster_board[ny3][nx3])
                    if max_amt < amt1 + amt2 + amt3:
                        max_amt = amt1 + amt2 + amt3
                        max_dir_seq = [dir1, dir2, dir3]
                path.pop()
            path.pop()

        # print(max_dir_seq)
        # print(max_amt)

        for i in range(3):
            next_dir = max_dir_seq[i]
            pacman_pos = [pacman_pos[0] + dy[next_dir], pacman_pos[1] + dx[next_dir]]
            if len(monster_board[pacman_pos[0]][pacman_pos[1]]) == 0:
                continue
            monster_board[pacman_pos[0]][pacman_pos[1]] = deque()
            dead_body[pacman_pos[0]][pacman_pos[1]] = time + 2

        # 4. clean dead monster
        for y in range(4):
            for x in range(4):
                if dead_body[y][x] == time:
                    dead_body[y][x] = -1
        # print("before born")
        # for y in range(4):
        #     for x in range(4):
        #         print(monster_board[y][x], end=' ')
        #     print()
        # print("---------")

        # 5. monster born
        for y in range(4):
            for x in range(4):
                for el in egg_board[y][x]:
                    monster_board[y][x].append(el)
                egg_board[y][x] = deque()

        # for y in range(4):
        #     for x in range(4):
        #         print(monster_board[y][x], end=' ')
        #     print()

    ans = 0
    for y in range(4):
        for x in range(4):
            ans += len(monster_board[y][x])

    print(ans)


solve()
