import sys
import math

input = sys.stdin.readline

cache = [
    [[[-1 for _ in range(101)] for _ in range(101)] for _ in range(101)]
    for _ in range(11)
]

N, R, G, B = map(int, input().split())


def dp(n, r, g, b):
    if cache[n][r][g][b] != -1:
        return cache[n][r][g][b]
    if n == N:
        return 1

    cache[n][r][g][b] = 0
    # add 1
    if r >= n + 1:
        cache[n][r][g][b] += dp(n + 1, r - n - 1, g, b)
    if g >= n + 1:
        cache[n][r][g][b] += dp(n + 1, r, g - n - 1, b)
    if b >= n + 1:
        cache[n][r][g][b] += dp(n + 1, r, g, b - n - 1)
    # add 2
    if (n + 1) % 2 == 0:
        if r >= (n + 1) // 2 and g >= (n + 1) // 2:
            cache[n][r][g][b] += math.comb(n + 1, (n + 1) // 2) * dp(
                n + 1, r - (n + 1) // 2, g - (n + 1) // 2, b
            )
        if g >= (n + 1) // 2 and b >= (n + 1) // 2:
            cache[n][r][g][b] += math.comb(n + 1, (n + 1) // 2) * dp(
                n + 1, r, g - (n + 1) // 2, b - (n + 1) // 2
            )
        if b >= (n + 1) // 2 and r >= (n + 1) // 2:
            cache[n][r][g][b] += math.comb(n + 1, (n + 1) // 2) * dp(
                n + 1, r - (n + 1) // 2, g, b - (n + 1) // 2
            )
    # add 3
    if (n + 1) % 3 == 0:
        if r >= (n + 1) // 3 and g >= (n + 1) // 3 and b >= (n + 1) // 3:
            cache[n][r][g][b] += (
                math.comb((n + 1), (n + 1) // 3)
                * math.comb((n + 1) // 3 * 2, (n + 1) // 3)
                * dp(n + 1, r - (n + 1) // 3, g - (n + 1) // 3, b - (n + 1) // 3)
            )

    return cache[n][r][g][b]


print(dp(0, R, G, B))
