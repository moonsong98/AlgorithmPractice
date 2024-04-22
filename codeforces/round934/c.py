import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    cnt = {}
    for el in a:
        if el in cnt:
            cnt[el] += 1
        else:
            cnt[el] = 1

    ans = -1
    cnt_single = 0
    nxt = 0
    for k, v in cnt.items():
        if k != nxt:
            ans = nxt
            break
        if k == nxt:
            nxt += 1

        if v == 1:
            cnt_single += 1
            if cnt_single == 2:
                ans = k
                break

    if ans == -1:
        print(max(a) + 1)
    else:
        print(ans)
