import sys

input = sys.stdin.readline

t = int(input())

while t > 0:
    t -= 1
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    k -= 1

    pos = n
    for i in range(n):
        if arr[i] > arr[k]:
            pos = i
            break
    if pos > k:
        print(pos - 1)
    else:
        pos2 = -1
        for i in range(pos + 1, k):
            if arr[i] > arr[k]:
                pos2 = i
                break

        ans1 = pos - 1
        ans2 = k - max(pos, 1) if pos2 == -1 else pos2 - max(pos, 1)
        print(max(ans1, ans2))
