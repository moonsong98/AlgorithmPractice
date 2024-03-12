import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

arr = []

while True:
    n = int(input())
    arr.append(n)
    if n == 0:
        break

for el in arr[::-1]:
    print(el)
