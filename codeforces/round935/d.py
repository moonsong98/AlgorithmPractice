import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

t = int(input())

while t:
    t -= 1
    n, m = list(map(int, input().split()))
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    cost = [0] * n
    cost[n - 1] = a[n - 1]
    minCost = min(a[n - 1], b[n - 1])
    for i in range(n - 2, -1, -1):
        cost[i] = minCost + a[i]
        minCost += min(a[i], b[i])
    ans = -1
    for i in range(0, m):
        if ans == -1 or ans > cost[i]:
            ans = cost[i]
    print(ans)
