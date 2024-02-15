import sys
from collections import deque, defaultdict

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

while T:
    T -= 1
    n, k = list(map(int, input().split()))
    adj = []
    for _ in range(n+2):
        adj.append(set())

    for _ in range(k):
        seq = list(map(int, input().split()))
        for idx in range(1, n-1):
            adj[seq[idx]].add(seq[idx+1])
    
    ans = True

    in_degree = [0] * (n+1)
    for u in range(1, n+1):
        for v in adj[u]:
            in_degree[v] += 1
        
    q = deque()
    for u in range(1, n+1):
        if in_degree[u] == 0:
            q.append(u)

    while len(q):
        u = q.popleft()
        for v in adj[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                q.append(v)

    print("YES" if not sum(in_degree) else "NO")