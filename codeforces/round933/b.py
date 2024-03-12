import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    arr = list(map(int, input().split()))

    for i in range(1, (n + 1) // 2):
        amt = arr[i - 1]
        arr[i - 1] = 0
        arr[i] -= 2 * amt
        arr[i + 1] -= amt
        if arr[i] < 0 or arr[i + 1] < 0:
            return False

        if n % 2 == 1 and i == (n + 1) // 2 - 1:
            break

        idx = n - i - 1
        amt = arr[idx + 1]
        arr[idx + 1] = 0
        arr[idx] -= 2 * amt
        arr[idx - 1] -= amt
        if arr[idx - 1] < 0 or arr[idx] < 0:
            return False

    for el in arr:
        if el > 0:
            return False

    return True


T = int(input())
for _ in range(T):
    print("YES" if solve() else "NO")
