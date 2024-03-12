import sys
import heapq

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))


def solve():
    n, l = list(map(int, input().split()))
    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().split())))

    arr.sort(key=lambda x: x[1])

    ans = 0
    for i in range(n):
        pq = []
        s = 0
        for j in range(i, n):
            heapq.heappush(pq, -arr[j][0])
            s += arr[j][0]
            while len(pq) and s + arr[j][1] - arr[i][1] > l:
                s += heapq.heappop(pq)
            ans = max(ans, len(pq))
    print(ans)


for _ in range(int(input())):
    solve()
