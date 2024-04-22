import sys
from collections import deque

input = sys.stdin.readline


def calc_dist(pos1, pos2):
    return abs(pos1[0] - pos2[0]) + abs(pos1[1] - pos2[1])


def solve():
    n, m = list(map(int, input().split()))
    board = [list(map(int, input().split())) for _ in range(n)]
    goal = [list(map(int, input().split())) for _ in range(m)]
    for i in range(m):
        for j in range(2):
            goal[i][j] -= 1
    reached = [False for _ in range(m)]
    basecamp = []
    in_board = []
    left = m

    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                basecamp.append((i, j))

    cur_time = 0
    dy = [-1, 0, 0, 1]
    dx = [0, -1, 1, 0]
    while True:
        cur_time += 1
        # if cur_time == 10:
        #     break
        # print(cur_time)
        # print(in_board)

        # 1. If person in a board, move to goal
        reached_this_turn = []
        if len(in_board):
            for i, el in enumerate(in_board):
                if reached[i]:
                    continue
                sy, sx = el
                q = deque()
                parent = [[None for _ in range(n)] for _ in range(n)]
                q.append((sy, sx, 0))
                parent[sy][sx] = [-1, -1]

                while len(q):
                    y, x, d = q.popleft()
                    # if cur_time == 4 and i == 2:
                    #     print("hihi")
                    #     print(y, x, d)
                    if [y, x] == goal[i]:
                        break
                    for next_dir in range(4):
                        ny, nx = y + dy[next_dir], x + dx[next_dir]
                        if not (0 <= ny < n and 0 <= nx < n):
                            continue
                        if board[ny][nx] == -1:
                            continue
                        if parent[ny][nx] is not None:
                            continue
                        parent[ny][nx] = [y, x]
                        q.append((ny, nx, d+1))

                y, x = goal[i]
                while True:
                    # if cur_time == 4 and i == 2:
                    #     print("haha")
                    #     print(y, x)
                    if parent[y][x] == [sy, sx]:
                        in_board[i] = [y, x]
                        break
                    y, x = parent[y][x]
                if in_board[i] == goal[i]:
                    reached_this_turn.append(i)

                # if cur_time == 4 and i == 2:
                #     print("==== parent ====")
                #     print(goal[i])
                #     for a in range(n):
                #         for b in range(n):
                #             print(parent[a][b], end=" ")
                #         print()
                #     print("==== parent ====")
        # for i in range(n):
        #     for j in range(n):
        #         print(board[i][j], end = ' ')
        #     print()

        # 2. Update reached_this_turn
        for el in reached_this_turn:
            left -= 1
            reached[el] = True
            board[goal[el][0]][goal[el][1]] = -1

        # print(in_board)

        # 3. Move person to basecamp
        if cur_time <= m:
            q = deque()
            q.append((goal[cur_time-1][0], goal[cur_time-1][1], 0))
            dist = [[0 for _ in range(n)] for _ in range(n)]
            dist[goal[cur_time-1][0]][goal[cur_time-1][1]] = -1
            # dy = [0, 1, 0, -1]
            # dx = [1, 0, -1, 0]
            while len(q):
                y, x, d = q.popleft()
                for next_dir in range(4):
                    ny, nx = y + dy[next_dir], x + dx[next_dir]
                    if not (0 <= ny < n and 0 <= nx < n):
                        continue
                    if board[ny][nx] == -1:
                        continue
                    if dist[ny][nx] != 0:
                        continue

                    dist[ny][nx] = d+1
                    q.append((ny, nx, d+1))

            min_dist = 1e6
            ny, nx = -1, -1
            for i in range(n):
                for j in range(n):
                    if board[i][j] > 0 and dist[i][j] > 0:
                        if dist[i][j] < min_dist:
                            min_dist = dist[i][j]
                            ny, nx = i, j

            board[ny][nx] = -1
            in_board.append([ny, nx])

        # for i in range(n):
        #     for j in range(n):
        #         print(board[i][j], end = ' ')
        #     print()
        # print(in_board)
        # print(reached)

        if left == 0:
            print(cur_time)
            return


solve()