import sys
import math

input = sys.stdin.readline

dp1 = dict()


def solve():
    MOD = 10**9 + 7

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

    # if cnt == 0:
    #     print(0)
    #     return

    ans = 1
    for i in range(1, cnt // 2 + 1):
        if (cnt, i) in dp1:
            value1 = dp1[(cnt, i)]
        else:
            value1 = math.comb(cnt, i) % MOD
            dp1[(cnt, i)] = value1

        value2 = math.perm(cnt - i, i) % MOD
        ans += value1 * value2

    print(ans % MOD)


t = int(input())

while t:
    t -= 1
    solve()
