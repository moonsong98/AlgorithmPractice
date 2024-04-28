import sys

input = sys.stdin.readline

n, m, x = list(map(int, input().split()))
arr = list(map(int, input().split()))
ans = [0 for _ in range(m)]
taken = 0


for i in range(m):
    l, r = 0, n - taken
    should_take = -1
    while l <= r:
        mid = l + (r - l) // 2
        if (arr[i] - arr[-1]) * mid + arr[-1] * (n - taken) <= x:
            should_take = mid
            l = mid + 1
        else:
            r = mid - 1

    taken += should_take
    x -= should_take * arr[i]
    ans[i] = should_take


print(*ans)
