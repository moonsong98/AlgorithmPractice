import sys

input = sys.stdin.readline


def move_forward(board, head, n):
    for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        ny, nx = head[0] + dy, head[1] + dx
        if not (0 <= ny < n and 0 <= nx < n):
            continue
        if board[ny][nx] == 3:
            # return head
            for dy2, dx2 in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                ny2, nx2 = ny + dy2, nx + dx2
                if not (0 <= ny2 < n and 0 <= nx2 < n):
                    continue
                if board[ny2][nx2] == 2:
                    board[ny2][nx2] = 3
                    board[head[0]][head[1]] = 2
                    board[ny][nx] = 1
                    return ny, nx

        if board[ny][nx] == 4:
            cur = head
            board[head[0]][head[1]] = 2
            head = (ny, nx)
            board[ny][nx] = 1
            prev = head

            while True:
                updated = False
                for dy2, dx2 in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    ny2, nx2 = cur[0] + dy2, cur[1] + dx2
                    if not (0 <= ny2 < n and 0 <= nx2 < n):
                        continue
                    if (ny2, nx2) == prev:
                        continue
                    if 0 < board[ny2][nx2] < 4:
                        updated = True
                        prev = cur
                        cur = (ny2, nx2)
                if not updated:
                    board[cur[0]][cur[1]] = 4
                    board[prev[0]][prev[1]] = 3
                    return head


def swap_head_tail(board, head, n):
    tail = None
    y, x = head
    prev = (-1, -1)
    while True:
        found = False
        for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ny, nx = y + dy, x + dx
            if (ny, nx) == prev:
                continue
            if not (0 <= ny < n and 0 <= nx < n):
                continue
            if board[ny][nx] == 2:
                prev = (y, x)
                y, x = ny, nx
                break
            if board[ny][nx] == 3:
                tail = (ny, nx)
                found = True
                break
        if found:
            break

    board[tail[0]][tail[1]] = 1
    board[head[0]][head[1]] = 3

    return tail


def find_head(board, point, n):
    if board[point[0]][point[1]] == 1:
        return 1, point

    dist_cand = []
    head = None
    for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        ny, nx = point[0] + dy, point[1] + dx
        if not (0 <= ny < n and 0 <= nx < n):
            continue
        if board[ny][nx] == 1:
            dist_cand.append(2)
            head = (ny, nx)
        elif board[ny][nx] == 2:
            cur = (ny, nx)
            prev = point
            dist = 1
            found = False
            is_head = False
            while True:
                for dy2, dx2 in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    ny, nx = cur[0] + dy2, cur[1] + dx2
                    if not (0 <= ny < n and 0 <= nx < n):
                        continue
                    if (ny, nx) == prev:
                        continue
                    if board[ny][nx] == 4 or board[ny][nx] == 0:
                        continue
                    dist += 1
                    # print(ny, nx)
                    if board[ny][nx] == 3:
                        found = True
                        cur = (ny, nx)
                        break
                    elif board[ny][nx] == 1:
                        found = True
                        is_head = True
                        cur = (ny, nx)
                        break
                    elif board[ny][nx] == 2:
                        prev = cur
                        cur = (ny, nx)
                if found:
                    break
            if is_head:
                dist_cand.append(dist+1)
                head = cur
    return max(dist_cand), head


def solve():
    n, m, k = list(map(int, input().split()))
    phase = 0
    cnt = 0
    ans = 0
    head = []

    board = [list(map(int, input().split())) for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                head.append((i, j))

    for turn in range(1, k + 1):
        # print("CNT:", cnt, " PHASE:", phase)
        for i in range(len(head)):
            head[i] = move_forward(board, head[i], n)

        # print("========AFTER MOVE============")
        # for i in range(n):
        #     for j in range(n):
        #         print(board[i][j], end=' ')
        #     print()
        # print(ans)

        dist = 0
        if phase == 0:
            for x in range(n):
                if 0 < board[cnt][x] < 4:
                    dist, head_pos = find_head(board, (cnt, x), n)
                    break

        elif phase == 1:
            for y in range(n - 1, -1, -1):
                if 0 < board[y][cnt] < 4:
                    dist, head_pos = find_head(board, (y, cnt), n)
                    break

        elif phase == 2:
            for x in range(n - 1, -1, -1):
                if 0 < board[n - 1 - cnt][x] < 4:
                    dist, head_pos = find_head(board, (n - 1 - cnt, x), n)
                    break

        elif phase == 3:
            for y in range(n):
                if 0 < board[y][n - 1 - cnt] < 4:
                    dist, head_pos = find_head(board, (y, n - 1 - cnt), n)
                    break

        ans += dist ** 2
        cnt += 1
        if cnt == n:
            phase = (phase + 1) % 4
            cnt = 0
        if dist > 0:
            # print(dist, head_pos)
            head_index = -1
            for i in range(len(head)):
                if head[i] == head_pos:
                    head_index = i
                    break
            # print(head[head_index])
            head[head_index] = swap_head_tail(board, head[head_index], n)
        # print("========TURN END============")
        # for i in range(n):
        #     for j in range(n):
        #         print(board[i][j], end=' ')
        #     print()
        # print(ans)

    # print("ANS:", ans)
    print(ans)
    # print("====================")
    # for i in range(n):
    #     for j in range(n):
    #         print(board[i][j], end=' ')
    #     print()


solve()
