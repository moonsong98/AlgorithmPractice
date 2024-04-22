import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n = int(input())
board = [[0] * n for _ in range(n)]

m = int(input())
for _ in range(m):
    y, x = list(map(int, input().split()))
    board[y - 1][x - 1] = 1

cmds = deque([tuple(input().split()) for _ in range(int(input()))])

body = deque([(0, 0)])

dy, dx = 0, 1


def change_dir(dy, dx, dir):
    if dir == "L":
        if dy == 0 and dx == 1:
            return -1, 0
        if dy == -1 and dx == 0:
            return 0, -1
        if dy == 0 and dx == -1:
            return 1, 0
        if dy == 1 and dx == 0:
            return 0, 1
    if dir == "D":
        if dy == 0 and dx == 1:
            return 1, 0
        if dy == 1 and dx == 0:
            return 0, -1
        if dy == 0 and dx == -1:
            return -1, 0
        if dy == -1 and dx == 0:
            return 0, 1


ans = 0
while True:
    head = body[0]
    ny, nx = head[0] + dy, head[1] + dx
    ans += 1

    if ny < 0 or ny >= n or nx < 0 or nx >= n or (ny, nx) in body:
        break

    if board[ny][nx] == 1:
        board[ny][nx] = 0
    else:
        body.pop()

    body.appendleft((ny, nx))

    if len(cmds) and cmds[0][0] == str(ans):
        dy, dx = change_dir(dy, dx, cmds.popleft()[1])

print(ans)
