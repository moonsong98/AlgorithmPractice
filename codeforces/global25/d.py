import sys

input = sys.stdin.readline

t = int(input())
while t:
    t -= 1
    n, k = list(map(int, input().split()))

    if n == k:
        print("YES")
        print(1)
        print(1)
    elif (n + 1) // 2 < k:
        print("No")
    else:
        print("YES")
        print(2)
        print(n - k + 1, 1)

    """
    n-k+1, 1
    n = 6, k = 4
    3 3
    so, n - k + 1 != n/2
    n = 7, k = 3
    5, 1, 1
    (n + 1) // 2
    n = 7, k = 4
    4, 1, 1, 1
    n = 6, k = 3
    4, 1, 1
    n = 10, k = 3
    8, 1, 1
    """
