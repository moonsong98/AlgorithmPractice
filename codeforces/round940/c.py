import sys

input = sys.stdin.readline

MOD = 10**9 + 7


def solve():
    n, k = list(map(int, input().split()))
    used = [False] * (n)

    for _ in range(k):
        a, b = list(map(lambda x: int(x) - 1, input().split()))
        used[a] = True
        used[b] = True

    cnt = 0
    for el in used:
        if not el:
            cnt += 1

    if cnt == 0:
        print(1)
        return

    dp = [0 for _ in range(cnt + 1)]
    dp[0] = 1
    dp[1] = 1

    for i in range(2, cnt + 1):
        dp[i] = (dp[i - 1] % MOD + (2 * (i - 1) * dp[i - 2]) % MOD) % MOD

    print(dp[cnt])


for _ in range(int(input())):
    solve()
