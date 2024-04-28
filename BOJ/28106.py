import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

MOD = 998244353
n = int(input())
p = [-1] + list(map(int, input().split()))
a = [-1] + list(map(int, input().split()))
reachable = [[] for _ in range(n + 1)]
child = [[] for _ in range(n + 1)]
isLeaf = [True for _ in range(n + 1)]

for node in range(1, n + 1):
    d = 1
    if p[node] > 0:
        isLeaf[p[node]] = False
        child[p[node]].append(node)
    original_node = node
    while p[node]:
        if a[p[node]] >= d:
            reachable[p[node]].append(original_node)
        node = p[node]
        d += 1

ans = 0
cnt = [0 for _ in range(n + 1)]


def dfs(node):
    global ans
    if isLeaf[node]:
        ans += cnt[node] % MOD
    for v in reachable[node]:
        cnt[v] += cnt[node] % MOD
    for v in child[node]:
        dfs(v)


for i in range(1, n + 1):
    if p[i] == 0:
        cnt[i] = 1
        dfs(i)


print(ans % MOD)
