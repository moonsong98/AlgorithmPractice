import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())
while T:
    T -= 1

    n, m, k, d = list(map(int, input().split()))

    min_costs = []
    pSum = [0]

    for _ in range(n):
        r = list(map(int, input().split()))
        dp = [-1] * (m)

        dp[0] = 1
        for i in range(m - 1):
            for j in range(1, d + 2):
                if i + j < m:
                    if dp[i + j] == -1:
                        dp[i + j] = dp[i] + r[i + j] + 1
                    else:
                        dp[i + j] = min(dp[i + j], dp[i] + r[i + j] + 1)

        min_costs.append(dp[m - 1])

    for i in range(n):
        pSum.append(pSum[i] + min_costs[i])

    ans = -1
    for i in range(k, n + 1):
        if ans == -1:
            ans = pSum[i] - pSum[i - k]
        else:
            ans = min(ans, pSum[i] - pSum[i - k])

    print(ans)
