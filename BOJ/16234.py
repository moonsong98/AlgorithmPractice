import sys
from collections import deque

input = sys.stdin.readline


def solution():
    n, l, r = list(map(int, input().split()))
    board = [list(map(int, input().split())) for _ in range(n)]
    ans = 0

    dy = [1, 0, -1, 0]
    dx = [0, 1, 0, -1]

    while True:
        has_group = [[False] * n for _ in range(n)]
        groups = []
        for y in range(n):
            for x in range(n):
                if has_group[y][x] == False:
                    has_group[y][x] = True
                    q = deque()
                    q.append((y, x))
                    tmp_group = [(y, x)]

                    while len(q):
                        cury, curx = q.popleft()
                        for i in range(4):
                            ny, nx = cury + dy[i], curx + dx[i]
                            if not (0 <= ny and ny < n and 0 <= nx and nx < n):
                                continue
                            if has_group[ny][nx]:
                                continue
                            diff = abs(board[cury][curx] - board[ny][nx])
                            if l <= diff and diff <= r:
                                tmp_group.append((ny, nx))
                                has_group[ny][nx] = True
                                q.append((ny, nx))

                    groups.append(tmp_group)

        if len(groups) == n**2:
            break
        for group in groups:
            s = 0
            for y, x in group:
                s += board[y][x]
            s //= len(group)
            for y, x in group:
                board[y][x] = s
        ans += 1

    print(ans)


solution()
