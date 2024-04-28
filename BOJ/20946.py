import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    is_prime = [True for _ in range(10**6 + 1)]
    arr = []

    for num in range(2, 10**6 + 1):
        if num > n:
            break
        if not is_prime[num]:
            continue

        while n % num == 0:
            arr.append(num)
            n //= num

        for i in range(num * 2, 10**6 + 1, num):
            is_prime[i] = False
    if n > 1:
        arr.append(n)
    if len(arr) == 1:
        print(-1)
    elif len(arr) < 3:
        ans = 1
        for el in arr:
            ans *= el
        print(ans)
    else:
        ans = []
        for i in range(1, len(arr), 2):
            ans.append(arr[i - 1] * arr[i])
        if len(arr) % 2:
            ans[-1] *= arr[-1]
        print(*ans)


solve()
