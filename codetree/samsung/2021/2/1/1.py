import sys
from collections import deque

input = sys.stdin.readline

n, m = list(map(int, input().split()))
board = [list(map(int, input().split())) for _ in range(n)]
score = [[0 for _ in range(n)] for _ in range(n)]


# dice rolling functions
def roll_right(dice):
    dice[0], dice[4], dice[1], dice[5] = dice[5], dice[0], dice[4], dice[1]


def roll_left(dice):
    dice[0], dice[4], dice[1], dice[5] = dice[4], dice[1], dice[5], dice[0]


def roll_up(dice):
    dice[0], dice[2], dice[1], dice[3] = dice[3], dice[0], dice[2], dice[1]


def roll_down(dice):
    dice[0], dice[2], dice[1], dice[3] = dice[2], dice[1], dice[3], dice[0]


# Create a score board
for i in range(n):
    for j in range(n):
        if score[i][j] == 0:
            cnt = 1
            discovered = [[False for _ in range(n)] for _ in range(n)]
            discovered[i][j] = True
            q = deque([(i, j)])
            while len(q):
                y, x = q.popleft()
                for dy, dx in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                    ny, nx = y + dy, x + dx
                    if not (0 <= ny < n and 0 <= nx < n):
                        continue
                    if discovered[ny][nx] or board[ny][nx] != board[i][j]:
                        continue
                    cnt += 1
                    discovered[ny][nx] = True
                    q.append((ny, nx))

            for y in range(n):
                for x in range(n):
                    if discovered[y][x]:
                        score[y][x] = board[i][j] * cnt

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
cur_dir = 0
cur_dice = [6, 1, 2, 5, 4, 3]
cur_pos = [0, 0]

ans = 0
for _ in range(m):
    tmp_pos = [cur_pos[0] + dy[cur_dir], cur_pos[1] + dx[cur_dir]]
    if not (0 <= tmp_pos[0] < n and 0 <= tmp_pos[1] < n):
        cur_dir = (cur_dir + 2) % 4
        tmp_pos = [cur_pos[0] + dy[cur_dir], cur_pos[1] + dx[cur_dir]]
    cur_pos = tmp_pos
    ans += score[cur_pos[0]][cur_pos[1]]
    if cur_dir == 0:
        roll_right(cur_dice)
    elif cur_dir == 1:
        roll_down(cur_dice)
    elif cur_dir == 2:
        roll_left(cur_dice)
    elif cur_dir == 3:
        roll_up(cur_dice)

    if cur_dice[0] > board[cur_pos[0]][cur_pos[1]]:
        cur_dir = (cur_dir + 1) % 4
    elif cur_dice[0] < board[cur_pos[0]][cur_pos[1]]:
        cur_dir = (cur_dir - 1) % 4

    # print(cur_dice[0], cur_pos, cur_dice)

print(ans)
