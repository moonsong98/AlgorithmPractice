import sys
from collections import deque

input = sys.stdin.readline


def back_track(board, viruses, chosen, left):
    if left == 0:
        board_c = [board[i][:] for i in range(len(board))]
        discovered = [[False for _ in range(len(board))] for _ in range(len(board))]
        q = deque()
        for el in chosen:
            q.append((viruses[el][0], viruses[el][1], 0))
            discovered[viruses[el][0]][viruses[el][1]] = True

        ret = 0
        while len(q):
            y, x, t = q.popleft()
            for dy, dx in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                ny, nx = y + dy, x + dx
                if not (0 <= ny < len(board) and 0 <= nx < len(board)):
                    continue
                if board_c[ny][nx] == 1 or discovered[ny][nx]:
                    continue
                discovered[ny][nx] = True
                if board_c[ny][nx] == 0:
                    board_c[ny][nx] = 2
                    ret = max(ret, t+1)
                q.append((ny, nx, t+1))

        for i in range(len(board)):
            for j in range(len(board)):
                if board_c[i][j] == 0:
                    return -1
        return ret

    ret = -1
    for i in range(0 if len(chosen) == 0 else chosen[-1]+1, len(viruses)):
        chosen.append(i)
        sub_ret = back_track(board, viruses, chosen, left-1)
        chosen.pop()
        if sub_ret == -1:
            continue
        if ret == -1 or sub_ret < ret:
            ret = sub_ret

    return ret


def solve():
    n, m = list(map(int, input().split()))
    board = [list(map(int, input().split())) for _ in range(n)]
    viruses = []
    for i in range(n):
        for j in range(n):
            if board[i][j] == 2:
                viruses.append((i, j))
    print(back_track(board, viruses, [], m))


solve()

