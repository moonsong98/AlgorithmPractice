import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n, m, s = list(map(int, input().split()))
adj = []
for _ in range(n+2):
    adj.append([])

for _ in range(m):
    u, v = list(map(int, input().split()))
    adj[u].append(v)
    adj[v].append(u)

for idx in range(1, n+1):
    adj[idx].sort()

def dfs(u):
    print(u, end = ' ')
    visited[u] = True
    for v in adj[u]:
        if visited[v]:
            continue
        dfs(v)
visited = [False] * (n+1)
dfs(s)
print()

q = deque()
q.append(s)
visited = [False] * (n+1)
visited[s] = True
while len(q):
    u = q.popleft()
    print(u, end = ' ')
    for v in adj[u]:
        if visited[v]:
            continue
        q.append(v)
        visited[v] = True