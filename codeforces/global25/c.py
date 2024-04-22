import sys

input = sys.stdin.readline

t = int(input())

while t:
    t -= 1
    n, m, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    d = dict()

    for i, el in enumerate(arr):
        if el in d:
            d[el].append(i)
        else:
            d[el] = [i]
    buy = [0 for _ in range(len(arr))]

    for key in sorted(d.keys()):
        tmp = sorted(d[key])
        for el in tmp:
            buy[el] = min(m, k)
            k -= buy[el]

    ans = 0
    bought = 0
    for i, el in enumerate(buy):
        ans += (arr[i] + bought) * el
        bought += el
    print(ans)
