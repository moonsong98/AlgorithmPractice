import sys

input = sys.stdin.readline

n, m = list(map(int, input().split()))

def func(arr, left):
    if left == 0:
        print(' '.join(arr))
        return
    for i in range(n):
        arr.append(str(i+1))
        func(arr, left-1)
        arr.pop()

func([], m)

