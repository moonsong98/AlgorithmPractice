import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(int(1e6))

t = int(input())

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

for _ in range(t):
    ans = False
    n = int(input())
    board = [input().strip() for _ in range(2)]
    discovered = [[False] * n for _ in range(2)]

    q = deque()
    q.append((0, 0))
    discovered[0][0] = True
    while len(q):
        y, x = q.popleft()
        if y == 1 and x == n - 1:
            ans = True
            break

        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if not (0 <= ny and ny < 2 and 0 <= nx and nx < n):
                continue
            nx = nx + (1 if board[ny][nx] == ">" else -1)
            if not (0 <= nx and nx < n):
                continue
            if discovered[ny][nx] == False:
                discovered[ny][nx] = True
                q.append((ny, nx))

    print("YES" if ans else "NO")
