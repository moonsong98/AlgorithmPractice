import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

t = int(input())

while t:
    t -= 1
    n, x = list(map(int, input().split()))
    arr = [0] + list(map(int, input().split()))

    cnt = 0
    ans = []
    idx = arr.index(x)
    mid = (n + 2) // 2
    if x <= mid:
        if idx != 0:
            cnt += 1
            ans.append((1, idx))
            tmp = arr[idx]
            arr[idx] = arr[1]
            arr[1] = tmp
        if arr[2] < arr[1]:
            for j in range(3, n + 1):
                if arr[j] > arr[1]:
                    cnt += 1
                    ans.append((2, j))
                    break
    else:
        if idx != n:
            cnt += 1
            ans.append((idx, n))
            tmp = arr[idx]
            arr[idx] = arr[n]
            arr[n] = tmp
        if arr[n - 1] > arr[n]:
            for j in range(1, n - 2):
                if arr[j] < arr[n]:
                    cnt += 1
                    ans.append((1, j))
                    break
