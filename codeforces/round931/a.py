import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

while T:
    T -= 1

    _ = input()
    arr = sorted(list(map(int, input().split())))

    print(
        abs(arr[0] - arr[-1])
        + abs(arr[-1] - arr[1])
        + abs(arr[1] - arr[-2])
        + abs(arr[-2] - arr[0])
    )
