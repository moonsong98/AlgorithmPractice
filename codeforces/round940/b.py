import sys

input = sys.stdin.readline


def solve():
    n, k = list(map(int, input().split()))

    if n == 1:
        print(k)
        return

    next_add = 2
    while next_add - 1 <= k:
        next_add *= 2

    next_add //= 2
    ans = [next_add - 1, k - next_add + 1]
    for i in range(2, n):
        ans.append(0)
    print(*ans)


t = int(input())

while t:
    t -= 1
    solve()
