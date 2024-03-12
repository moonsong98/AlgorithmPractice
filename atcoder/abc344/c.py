import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

posVal = set()

n = int(input())
A = list(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))
l = int(input())
L = list(map(int, input().split()))

for el1 in range(n):
    for el2 in range(m):
        for el3 in range(l):
            posVal.add(A[el1] + B[el2] + L[el3])

q = int(input())
X = list(map(int, input().split()))

for el in X:
    print("Yes" if el in posVal else "No")
