import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))


def solve():
    n = int(input())
    arr = []
    for _ in range(2):
        arr.append(list(map(int, list(input().strip()))))
    ans1 = str(arr[0][0])
    ans2 = 1

    for i in range(n - 1):
        if arr[0][i + 1] == arr[1][i]:
            ans1 += str(arr[0][i + 1])
            ans2 += 1
        elif arr[0][i + 1] < arr[1][i]:
            ans1 += str(arr[0][i + 1])
            ans2 = 1
        else:
            for j in range(i, n):
                ans1 += str(arr[1][j])
            break
    if len(ans1) <= n:
        ans1 += str(arr[1][n - 1])
    print(ans1)
    print(ans2)


T = int(input())
for _ in range(T):
    solve()
