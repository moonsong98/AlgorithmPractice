import sys

input = sys.stdin.readline


def round(a):
    if a - int(a) >= 0.5:
        return int(a) + 1
    return int(a)


n = int(input())
if n == 0:
    print(0)
else:
    arr = [int(input()) for _ in range(n)]
    arr.sort()

    cut = round(n * 0.15)
    if cut == 0:
        ans = round(sum(arr) / n)
    else:
        ans = round(sum(arr[cut:-cut]) / (n - 2 * cut))
    print(ans)
