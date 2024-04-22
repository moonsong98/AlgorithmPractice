import sys

input = sys.stdin.readline

dy = [0, -1, -1, -1, 0, 1, 1, 1]
dx = [1, 1, 0, -1, -1, -1, 0, 1]

n, m = list(map(int, input().split()))
board = [list(map(int, input().split())) for _ in range(n)]

food = [[n - 2, 0], [n - 1, 0], [n - 2, 1], [n - 1, 1]]

for _ in range(m):
    d, p = list(map(int, input().split()))
    for i in range(len(food)):
        food[i] = [(food[i][0] + p * dy[d - 1]) % n, (food[i][1] + p * dx[d - 1]) % n]

    for i in range(len(food)):
        board[food[i][0]][food[i][1]] += 1
    # print("===== after food eaten =====")
    # for i in range(n):
    #     for j in range(n):
    #         print(board[i][j], end=' ')
    #     print()
    # print("===========================")

    for i in range(len(food)):
        for next_dir in [1, 3, 5, 7]:
            ny, nx = food[i][0] + dy[next_dir], food[i][1] + dx[next_dir]
            if 0 <= ny < n and 0 <= nx < n:
                if board[ny][nx] > 0:
                    board[food[i][0]][food[i][1]] += 1

    # print("===== after neighbor eaten =====")
    # for i in range(n):
    #     for j in range(n):
    #         print(board[i][j], end=' ')
    #     print()
    # print("===========================")

    tmp_food = []
    for i in range(n):
        for j in range(n):
            if [i, j] in food:
                continue
            if board[i][j] >= 2:
                board[i][j] -= 2
                tmp_food.append([i, j])
    # print("===== after create food =====")
    # for i in range(n):
    #     for j in range(n):
    #         print(board[i][j], end=' ')
    #     print()
    # print("===========================")
    food = tmp_food[:]
    # print(food)

ans = 0
for i in range(n):
    for j in range(n):
        ans += board[i][j]

print(ans)
