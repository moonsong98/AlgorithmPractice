import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))


def find_pal(l, r, dp, string):
    if dp[l][r] != -1:
        return dp[l][r]
    elif l == r:
        dp[l][r] = True
        dp[l][r] = True

    mid = dp[l + 1][r - 1]
    if mid and string[l] == string[r]:
        dp[l][r] = True
    else:
        dp[l][r] = False
    return dp[l][r]


t = int(input())
for _ in range(t):
    n, q = list(map(int, input().split()))
    string = input().strip()
    dp = [[-1] * n for _ in range(n)]
    for i in range(n):
        for j in range(i, n):
            if dp[i][j] == -1:
                find_pal(i, j, dp, string)

    for _ in range(q):
        l, r = list(map(int, input().split()))
        print((2 + (r - l + 1)) * (r - l) // 2)
