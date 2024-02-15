import sys
import heapq

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n, x = list(map(int, input().split()))
arr = list(map(int, input().split()))

l, r = 1, n
ans = -1

while l <= r:
    mid = l + (r-l) // 2
    pq = [0] * mid
    heapq.heapify(pq)

    for el in arr:
        top = heapq.heappop(pq)
        top += el
        heapq.heappush(pq, top)
    
    max_val = max(pq)
    
    if max_val <= x:
        ans = mid
        r = mid - 1 
    else:
        l = mid + 1

print(ans)