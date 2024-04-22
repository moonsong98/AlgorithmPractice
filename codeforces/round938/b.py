import sys

input = sys.stdin.readline


def solve():
    t = int(input())
    while t:
        t -= 1
        n, c, d = list(map(int, input().split()))
        arr = list(map(int, input().split()))
        board = [[0 for _ in range(n)] for _ in range(n)]
        board[0][0] = min(arr)
        for i in range(1, n):
            board[0][i] = board[0][i - 1] + d
        for i in range(1, n):
            for j in range(n):
                board[i][j] = board[i - 1][j] + c

        final_arr = []
        for i in range(n):
            final_arr += board[i]

        print("YES" if sorted(arr) == sorted(final_arr) else "NO")


solve()
