import sys

input = sys.stdin.readline


def dist(pos1, pos2):
    return abs(pos1[0] - pos2[0]) + abs(pos1[1] - pos2[1])


def solve():
    n, m, k = list(map(int, input().split()))
    board = [list(map(int, input().split())) for _ in range(n)]
    participant_board = [[set() for _ in range(n)] for _ in range(n)]

    participants = []
    is_done = [False for _ in range(m)]
    left = m

    # add participants
    for i in range(m):
        y, x = list(map(int, input().split()))
        y -= 1
        x -= 1
        participant_board[y][x].add(i)
        participants.append([y, x])

    # save goal info
    goal = list(map(int, input().split()))
    goal[0] -= 1
    goal[1] -= 1

    # answer
    total_movement = 0

    dy = [1, -1, 0, 0]
    dx = [0, 0, 1, -1]
    for _ in range(k):
        # move participants
        for i, p in enumerate(participants):
            if is_done[i]:
                continue
            y, x = p
            cur_dist = dist(p, goal)
            min_dist = -1
            min_dist_dir = -1
            for j in range(4):
                ny, nx = y + dy[j], x + dx[j]
                if not (0 <= ny < n and 0 <= nx < n):
                    continue
                if board[ny][nx] > 0:
                    continue
                new_dist = dist([ny, nx], goal)
                if new_dist >= cur_dist:
                    continue
                if min_dist == -1 or new_dist < min_dist:
                    min_dist = new_dist
                    min_dist_dir = j

            if min_dist_dir != -1:
                ny, nx = y + dy[min_dist_dir], x + dx[min_dist_dir]
                total_movement += 1
                participant_board[y][x].remove(i)

                if [ny, nx] == goal:
                    is_done[i] = True
                    left -= 1
                else:
                    participants[i] = [ny, nx]
                    participant_board[ny][nx].add(i)

        if left == 0:
            break
        # rotate board
        rotate_size = -1
        rotate_s_pos = []

        for size in range(2, n+1):
            for sy in range(max(0, goal[0] - size + 1), min(n - size + 1, goal[0] + 1)):
                for sx in range(max(0, goal[1] - size + 1), min(n - size + 1, goal[1] + 1)):
                    has_participant = False
                    for i in range(sy, sy + size):
                        for j in range(sx, sx + size):
                            if len(participant_board[i][j]) > 0:
                                has_participant = True

                    if has_participant:
                        rotate_size = size
                        rotate_s_pos = [sy, sx]
                        break
                if rotate_size > -1:
                    break
            if rotate_size > -1:
                break

        if rotate_size != -1:
            new_board = [[0 for _ in range(rotate_size)] for _ in range(rotate_size)]
            tmp_board = [[0 for _ in range(rotate_size)] for _ in range(rotate_size)]

            new_participant_board = [[0 for _ in range(rotate_size)] for _ in range(rotate_size)]
            tmp_participant_board = [[0 for _ in range(rotate_size)] for _ in range(rotate_size)]

            sy, sx = rotate_s_pos
            for y in range(sy, sy + rotate_size):
                for x in range(sx, sx + rotate_size):
                    tmp_board[y - sy][x - sx] = board[y][x]
                    tmp_participant_board[y - sy][x - sx] = participant_board[y][x]

            tmp_goal = [goal[0] - sy, goal[1] - sx]
            tmp_goal = [tmp_goal[1], rotate_size - 1 - tmp_goal[0]]
            goal = [tmp_goal[0] + sy, tmp_goal[1] + sx]

            for y in range(rotate_size):
                for x in range(rotate_size):
                    new_board[x][rotate_size - 1 - y] = tmp_board[y][x]
                    new_participant_board[x][rotate_size - 1 - y] = tmp_participant_board[y][x]

            for y in range(sy, sy + rotate_size):
                for x in range(sx, sx + rotate_size):
                    board[y][x] = new_board[y - sy][x - sx]
                    if board[y][x] > 0:
                        board[y][x] -= 1
                    participant_board[y][x] = new_participant_board[y - sy][x - sx]
                    for pi in participant_board[y][x]:
                        participants[pi] = [y, x]
    #
    #         print("--------------------")
    #         for y in range(n):
    #             for x in range(n):
    #                 print(board[y][x], end=' ')
    #             print()
    #         print()
    #
    #         for y in range(n):
    #             for x in range(n):
    #                 print(participant_board[y][x], end=' ')
    #             print()
    #         print()
    #
    #         print(goal)
    #
    # print("--------------------")
    print(total_movement)
    print(goal[0] + 1, goal[1] + 1)


solve()
