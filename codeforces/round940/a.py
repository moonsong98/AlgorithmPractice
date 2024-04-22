import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    d = dict()
    for el in arr:
        if el not in d:
            d[el] = 1
        else:
            d[el] += 1

    ans = 0
    for k, v in d.items():
        if v > 2:
            ans += v // 3

    print(ans)


t = int(input())
while t:
    t -= 1
    solve()
