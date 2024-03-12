import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    str = input().strip()

    ans = 0
    arr = []
    chr = str[0]
    cnt = 1
    for i in range(1, n):
        if chr != str[i]:
            arr.append([chr, cnt])
            chr = str[i]
            cnt = 1
        else:
            cnt += 1
    arr.append([chr, cnt])

    for i in range(len(arr)):
        if i < len(arr) - 4:
            if (
                str[i : i + 5] == "mapie"
                and arr[i][0] == "m"
                and arr[i][1]
                and arr[i + 1][0] == "a"
                and arr[i + 1][1] == 1
                and arr[i + 2][0] == "p"
                and arr[i + 2][1] == 1
                and arr[i + 3][0] == "i"
                and arr[i + 3][1] == 1
                and arr[i + 4][0] == "e"
                and arr[i + 4][1]
            ):
                if arr[i + 2][1] < arr[i + 1][1] + arr[i + 3][1]:
                    ans += arr[i + 2][1]
                    arr[i + 2][1] = 0
                else:
                    ans += arr[i + 1][1] + arr[i + 3][1]
                    arr[i + 1][1] = 0
                    arr[i + 3][1] = 0

        if i < len(arr) - 2:
            if (
                arr[i][0] == "m"
                and arr[i][1]
                and arr[i + 1][0] == "a"
                and arr[i + 1][1] == 1
                and arr[i + 2][0] == "p"
                and arr[i + 2][1]
            ):
                minVal = min(arr[i][1], arr[i + 1][1], arr[i + 2][1])
                if arr[i + 2][1] == minVal:
                    arr[i + 2][1] = 0
                elif arr[i + 1][1] == minVal:
                    arr[i + 1][1] = 0
                else:
                    arr[i][1] = 0
                ans += minVal
            if (
                arr[i][0] == "p"
                and arr[i][1]
                and arr[i + 1][0] == "i"
                and arr[i + 1][1] == 1
                and arr[i + 2][0] == "e"
                and arr[i + 2][1]
            ):
                minVal = min(arr[i][1], arr[i + 1][1], arr[i + 2][1])
                if arr[i + 2][1] == minVal:
                    arr[i + 2][1] = 0
                elif arr[i + 1][1] == minVal:
                    arr[i + 1][1] = 0
                else:
                    arr[i][1] = 0
                ans += minVal
    print(ans)


T = int(input())
for _ in range(T):
    solve()
