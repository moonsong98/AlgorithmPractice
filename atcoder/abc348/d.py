import sys
from collections import deque

input = sys.stdin.readline

h, w = list(map(int, input().split()))
board = [list(input().strip()) for _ in range(h)]
s, e = [], []
n = int(input())
for i in range(h):
    for j in range(w):
        if board[i][j] == "S":
            s = [i, j]
            board[i][j] = 0
        elif board[i][j] == "T":
            e = [i, j]
            board[i][j] = (0, n + 1)
points = []
for i in range(n):
    r, c, energy = list(map(int, input().split()))
    board[r - 1][c - 1] = (energy, i + 1)
    points.append([r - 1, c - 1])
points.append(e)

if board[s[0]][s[1]] == 0:
    print("No")
else:
    adj = [[] for _ in range(n + 1)]
    dy = [1, 0, -1, 0]
    dx = [0, 1, 0, -1]

    for i, p in enumerate(points):
        q = deque()
        q.append((*p, int(board[p[0]][p[1]][0])))
        discovered = [[False for _ in range(w)] for _ in range(h)]
        discovered[p[0]][p[1]] = True

        while len(q):
            y, x, left = q.popleft()
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                if not (0 <= ny < h and 0 <= nx < w):
                    continue
                if discovered[ny][nx] or board[ny][nx] == "#":
                    continue
                discovered[ny][nx] = True
                if board[ny][nx] != ".":
                    adj[i].append(board[ny][nx][1])
                if left > 1:
                    q.append((ny, nx, left - 1))

    ans = False
    q = deque()
    discovered = [False for _ in range(len(adj))]
    q.append(board[s[0]][s[1]][1])
    discovered[q[0]] = True

    while len(q):
        u = q.popleft()
        if u == n:
            ans = True
            break
        for v in adj[u]:
            print(v, discovered[v])
            if not discovered[v]:
                q.append(v)
                discovered[v] = True

    print(points)
    for i, el in enumerate(adj):
        print(i, el)

    print("Yes" if ans else "No")
