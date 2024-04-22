import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

t = int(input())

for _ in range(t):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    l = sorted(arr[0:n])
    r = sorted(arr[n : 2 * n])
    if l == r:
        print(*l[0 : 2 * k])
        print(*r[0 : 2 * k])
        continue

    l_cnt = {}
    r_cnt = {}

    for el in l:
        if el in l_cnt:
            l_cnt[el] += 1
        else:
            l_cnt[el] = 1
    for el in r:
        if el in r_cnt:
            r_cnt[el] += 1
        else:
            r_cnt[el] = 1
    l_cnt = sorted(l_cnt.items(), key=lambda x: -x[1])
    r_cnt = sorted(r_cnt.items(), key=lambda x: -x[1])

    cnt = 0
    l, r = [], []
    idx = 0
    while cnt < 2 * k:
        for _ in range(l_cnt[idx][1]):
            l.append(l_cnt[idx][0])
        for _ in range(r_cnt[idx][1]):
            r.append(r_cnt[idx][0])
        cnt += l_cnt[idx][1]
        idx += 1

    print(*l)
    print(*r)
