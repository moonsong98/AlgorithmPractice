import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))


def solve():
    n = int(input())
    cmp = 1
    ans = 0

    while True:
        if cmp <= n:
            ans = cmp
            cmp *= 2
        else:
            print(ans)
            return


T = int(input())
for _ in range(T):
    solve()
