import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n, l = list(map(int, input().split()))
board = [list(map(int, input().split())) for _ in range(n)]

ans = 0
for i in range(n):
    j = 1
    cnt = 1
    valid = True
    while j < n:
        if board[i][j] == board[i][j - 1]:
            cnt += 1
        elif abs(board[i][j] - board[i][j - 1]) >= 2:
            valid = False
            break
        elif board[i][j] > board[i][j - 1]:
            if cnt >= l:
                cnt = 1
            else:
                valid = False
                break
        else:
            cnt = 0
            if j + l - 1 >= n:
                valid = False
                break
            for k in range(1, l):
                if board[i][j + k] != board[i][j]:
                    valid = False
                    break
            if not valid:
                break
            j += l - 1
        j += 1
    if valid:
        ans += 1

for i in range(n):
    j = 1
    cnt = 1
    valid = True
    while j < n:
        if board[j][i] == board[j - 1][i]:
            cnt += 1
        elif abs(board[j][i] - board[j - 1][i]) >= 2:
            valid = False
            break
        elif board[j][i] > board[j - 1][i]:
            if cnt >= l:
                cnt = 1
            else:
                valid = False
                break
        else:
            cnt = 0
            if j + l - 1 >= n:
                valid = False
                break
            for k in range(1, l):
                if board[j + k][i] != board[j][i]:
                    valid = False
                    break
            if not valid:
                break
            j += l - 1
        j += 1
    if valid:
        ans += 1


print(ans)
