import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

while T:
    n = int(input())
    arr = list(map(int, input().split()))
    cnt_l, cnt_r = 0, 0

    for idx in range(len(arr)):
        if arr[idx] == arr[0]:
            cnt_l += 1
        else:
            break
    
    for idx in range(len(arr)-1, -1, -1):
        if arr[idx] == arr[len(arr)-1]:
            cnt_r += 1
        else:
            break
    if arr[0] == arr[n-1]:
        if cnt_l == n:
            print(0)
        else:
            print(n - cnt_l - cnt_r)
    else:
        print(n - max(cnt_l, cnt_r))
    T -= 1