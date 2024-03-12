import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

dp = [0] + [-1] * int(29)
for i in range(0, 30):
    if i + 1 < 30:
        if dp[i+1] == -1:
            dp[i+1] = dp[i] + 1
        else:
            dp[i+1] = min(dp[i+1], dp[i] + 1)
    if i + 3 < 30:
        if dp[i+3] == -1:
            dp[i+3] = dp[i] + 1
        else:
            dp[i+3] = min(dp[i+3], dp[i] + 1)
    if i + 6 < 30:
        if dp[i+6] == -1:
            dp[i+6] = dp[i] + 1
        else:
            dp[i+6] = min(dp[i+6], dp[i] + 1)
    if i + 10 < 30:
        if dp[i+10] == -1:
            dp[i+10] = dp[i] + 1
        else:
            dp[i+10] = min(dp[i+10], dp[i] + 1)
    if i + 15 < 30:
        if dp[i+15] == -1:
            dp[i+15] = dp[i] + 1
        else:
            dp[i+15] = min(dp[i+15], dp[i] + 1)

while T:
    T -= 1
    n = int(input())
    ans = n
    if n < 30:
        print(dp[n])
    else:
        ans = min(n // 15 + dp[n % 15], n // 15 - 1 + dp[n%15 + 15])
        print(ans)

        