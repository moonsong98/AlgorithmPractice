import sys

input = sys.stdin.readline

n = int(input())
arr = []

while n:
    c = input().rstrip()
    if len(c) > 1:
        c, a = list(map(int, c.split()))
    else:
        c = int(c)

    if c == 1:
        arr.append(a)
    elif c == 2:
        print(-1 if len(arr) == 0 else arr.pop())
    elif c == 3:
        print(len(arr))
    elif c == 4:
        print(1 if len(arr) == 0 else 0)
    elif c == 5:
        print(arr[len(arr) - 1] if len(arr) > 0 else -1)

    n -= 1
