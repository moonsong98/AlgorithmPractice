import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n, k = list(map(int, input().split()))
arr = list(map(int, input().split()))

for el in arr:
    if el % k == 0:
        print(el // k, end=" ")
