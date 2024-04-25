import sys
import bisect
import heapq

input = sys.stdin.readline


def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    d = dict()

    for i in range(n):
        if arr[i] in d:
            d[arr[i]].append(i)
        else:
            d[arr[i]] = [i]

    checked = []
    flag = False
    for num in sorted(d.keys(), key=lambda x: -x):
        l = d[num]
        for idx in range(1, len(l)):
            a = bisect.bisect(checked, l[idx - 1])
            b = bisect.bisect(checked, l[idx])
            if a != b:
                flag = True
                break

        for el in l:
            bisect.insort(checked, el)

        if flag is True:
            break

    print("No" if flag else "Yes")


for _ in range(int(input())):
    solve()
