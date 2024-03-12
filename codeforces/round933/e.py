import sys
from collections import deque

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

        dp = [1]
        q = deque([(1, 0)])
        for i in range(1, m):
            dp.append(q[0][0] + r[i] + 1)
            while len(q) and q[-1][0] >= dp[-1]:
                q.pop()
            while len(q) and q[0][1] < i - d:
                q.popleft()
            q.append((dp[-1], i))
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
