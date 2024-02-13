import sys
input = sys.stdin.readline

n, k = [int(input()) for _ in range(2)]
l, r = 1, n**2

ans = -1

while l <= r:
    mid = l + (r-l) // 2
    cnt = 0

    for el in range(1, n+1):
        cnt += min(mid // el, n)
    
    if cnt >= k:
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

print(ans)
