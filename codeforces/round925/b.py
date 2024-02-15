import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

while T:
    n = int(input())
    arr = list(map(int, input().split()))
    avg = sum(arr) // n
    left = 0
    for el in arr:
        if el >= avg:
            left += el - avg
        else:
            left += el - avg
            if left < 0:
                break
    print("NO" if left < 0 else "YES")
    T-=1