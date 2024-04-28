import sys
from collections import deque

input = sys.stdin.readline


def solve():
    N = int(input())
    board = [list(map(int, input().split())) for _ in range(N)]
    not_eaten = []
    can_eat = set()
    level, ate = 2, 0
    ans = 0
    cur_pos = None

    for i in range(N):
        for j in range(N):
            if board[i][j] == 9:
                cur_pos = [i, j]
                board[i][j] = 0

    dy = [0, 1, 0, -1]
    dx = [1, 0, -1, 0]
    while True:
        q = deque()
        discovered = [[False for _ in range(N)] for _ in range(N)]
        discovered[cur_pos[0]][cur_pos[1]] = True
        q.append((cur_pos[0], cur_pos[1], 0))

        min_dist = -1
        food_pos = [-1, -1]
        while len(q) > 0:
            y, x, dist = q.popleft()
            if min_dist > -1 and dist > min_dist:
                break
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                if not (0 <= ny and ny < N and 0 <= nx and nx < N):
                    continue
                if discovered[ny][nx]:
                    continue
                if board[ny][nx] > level:
                    continue
                if 0 < board[ny][nx] and board[ny][nx] < level:
                    if (
                        min_dist == -1
                        or dist + 1 < min_dist
                        or (
                            dist + 1 == min_dist
                            and (
                                ny < food_pos[0]
                                or (ny == food_pos[0] and nx < food_pos[1])
                            )
                        )
                    ):
                        min_dist = dist + 1
                        food_pos = [ny, nx]

                discovered[ny][nx] = True
                q.append((ny, nx, dist + 1))

        if min_dist == -1:
            break

        ate += 1
        ans += min_dist
        if ate == level:
            level += 1
            ate = 0

        board[food_pos[0]][food_pos[1]] = 0
        cur_pos = food_pos

    print(ans)


solve()
