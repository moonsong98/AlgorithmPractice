import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
ans = -1


def bt(cnt, cury, curx):
    global ans
    if cnt == 3:
        visited = [[False] * m for _ in range(n)]
        q = deque()
        for i in range(n):
            for j in range(m):
                if board[i][j] == 2:
                    q.append((i, j))
                    while len(q):
                        y, x = q.popleft()
                        for dy, dx in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
                            ny, nx = y + dy, x + dx
                            if (
                                0 <= ny < n
                                and 0 <= nx < m
                                and not visited[ny][nx]
                                and board[ny][nx] == 0
                            ):
                                q.append((ny, nx))
                                visited[ny][nx] = True

        cnt_zero = 0
        for i in range(n):
            for j in range(m):
                if board[i][j] == 0 and visited[i][j] == False:
                    cnt_zero += 1
        ans = max(ans, cnt_zero)

        return

    for x in range(curx, m):
        if board[cury][x] == 0:
            board[cury][x] = 1
            bt(cnt + 1, cury, x)
            board[cury][x] = 0

    for y in range(cury + 1, n):
        for x in range(0, m):
            if board[y][x] == 0:
                board[y][x] = 1
                bt(cnt + 1, y, x)
                board[y][x] = 0


bt(0, 0, 0)
print(ans)
