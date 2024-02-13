import sys

input = sys.stdin.readline

n, s = list(map(int, input().split()))
arr = list(map(int, input().split()))

ans = 0
l, r, cur_sum = 0, 0, arr[0]

while True:
    if cur_sum < s:
        r += 1
        if r == n:
            break
        cur_sum += arr[r]
    elif cur_sum >= s:
        if ans == 0 or ans > r - l + 1:
            ans = r - l + 1
        cur_sum -= arr[l]
        l += 1
        if l == n:
            break
        if l > r:
            r += 1
            cur_sum += arr[r]

print(ans)
