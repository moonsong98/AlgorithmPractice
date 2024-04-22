import sys

input = sys.stdin.readline

n = int(input())
s = [list(map(int, input().split())) for _ in range(n)]

ans = -1


def bt(nxt_schedule, cost):
    global ans
    if nxt_schedule > n:
        return
    if nxt_schedule == n:
        ans = max(ans, cost)
        return

    bt(nxt_schedule + 1, cost)
    bt(nxt_schedule + s[nxt_schedule][0], cost + s[nxt_schedule][1])


bt(0, 0)

print(ans)
