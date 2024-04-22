import sys

input = sys.stdin.readline

n = int(input())
seat = [None for _ in range(n ** 2 + 1)]
board = [[-1 for _ in range(n)] for _ in range(n)]

friend_map = dict()

for _ in range(n ** 2):
    a, b, c, d, e = map(int, input().split())
    friends = [b, c, d, e]
    friend_map[a] = friends

    max_num_friend = -1
    max_space = -1
    max_seat = (-1, -1)

    for i in range(4):
        friend = friends[i]
        if seat[friend] is None:
            continue

        for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ny, nx = seat[friend][0] + dy, seat[friend][1] + dx
            if not (0 <= ny < n and 0 <= nx < n):
                continue
            if board[ny][nx] == -1:
                num_space = 0
                num_friend = 0
                for dy2, dx2 in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    ny2, nx2 = ny + dy2, nx + dx2
                    if not (0 <= ny2 < n and 0 <= nx2 < n):
                        continue
                    if board[ny2][nx2] == -1:
                        num_space += 1
                    elif board[ny2][nx2] in friends:
                        num_friend += 1

                if num_friend > max_num_friend or (num_friend == max_num_friend and (num_space > max_space or (
                        num_space == max_space and (
                        max_seat[0] > ny or (max_seat[0] == ny and max_seat[1] > nx))))):
                    max_num_friend = num_friend
                    max_space = num_space
                    max_seat = (ny, nx)

    if max_seat != (-1, -1):
        seat[a] = max_seat
        board[max_seat[0]][max_seat[1]] = a
    else:
        max_cnt = -1
        max_pos = [-1, -1]
        for i in range(n):
            for j in range(n):
                if board[i][j] == -1:
                    cnt = 0
                    for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                        ny, nx = i + dy, j + dx
                        if not (0 <= ny < n and 0 <= nx < n):
                            continue
                        if board[ny][nx] == -1:
                            cnt += 1

                    if cnt > max_cnt:
                        max_cnt = cnt
                        max_pos = (i, j)

        seat[a] = max_pos
        board[max_pos[0]][max_pos[1]] = a

ans = 0
for i in range(n):
    for j in range(n):
        cnt = 0
        for dy, dx in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
            ny, nx = i + dy, j + dx
            if not (0 <= ny < n and 0 <= nx < n):
                continue
            if board[ny][nx] in friend_map[board[i][j]]:
                cnt += 1

        ans += 0 if cnt == 0 else 10 ** (cnt - 1)

print(ans)
