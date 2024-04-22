import sys
import heapq

input = sys.stdin.readline


def solve():
    n, m = list(map(int, input().split()))
    adj = [[] for _ in range(n + 1)]
    num_connected = [0 for _ in range(n + 1)]

    for _ in range(m):
        u, v = list(map(int, input().split()))
        adj[u].append(v)
        num_connected[v] += 1

    pq = []
    for u in range(1, n + 1):
        if num_connected[u] == 0:
            heapq.heappush(pq, u)

    while len(pq) > 0:
        u = heapq.heappop(pq)
        for v in adj[u]:
            num_connected[v] -= 1
            if num_connected[v] == 0:
                heapq.heappush(pq, v)

        print(u, end=" ")


solve()
