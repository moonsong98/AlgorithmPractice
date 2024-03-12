import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

N, L = map(int, input().split())
arr = map(int, input().split())

q = deque()
ans = []

# (value, index)

for i, el in enumerate(arr):
    while len(q) and q[-1][0] >= el:
        q.pop()
    while len(q) and q[0][1] <= i - L:
        q.popleft()

    q.append((el, i))
    print(q[0][0], end=" ")

print()
