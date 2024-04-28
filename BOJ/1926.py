import sys
from collections import deque

input = sys.stdin.readline

n, m = list(map(int, input().split()))
board = [list(map(int, input().split())) for _ in range(n)]
discovered = [[False for _ in range(m)] for _ in range(n)]

ans = 0
cnt = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 1 and not discovered[i][j]:
            discovered[i][j] = True
            q = deque()
            q.append((i, j))
            area = 1
            cnt += 1
            while len(q) > 0:
                y, x = q.popleft()
                for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                    ny, nx = y + dy, x + dx
                    if 0 <= ny < n and 0 <= nx < m:
                        if board[ny][nx] == 1 and not discovered[ny][nx]:
                            area += 1
                            discovered[ny][nx] = True
                            q.append((ny, nx))
            ans = max(ans, area)

print(cnt)
print(ans)



