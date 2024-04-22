import sys
from collections import Counter

input = sys.stdin.readline


def solve():
    n, m, k = list(map(int, input().split()))
    arr1 = [str(x) for x in input().split()]
    arr2 = [str(x) for x in input().split()]
    # arr1 = list(map(int, input().split()))
    # arr2 = list(map(int, input().split()))
    num_matches = 0
    need = Counter(arr2)
    window = Counter(arr1[:m])

    for el in window:
        num_matches += min(need[el], window[el])

    ans = 1 if num_matches >= k else 0

    for i in range(m, n):
        window[arr1[i - m]] -= 1
        if window[arr1[i - m]] < need[arr1[i - m]]:
            num_matches -= 1

        window[arr1[i]] += 1

        if window[arr1[i]] <= need[arr1[i]]:
            num_matches += 1

        if num_matches >= k:
            ans += 1

    # print("ANS:", ans)
    print(ans)


for _ in range(int(input())):
    solve()
