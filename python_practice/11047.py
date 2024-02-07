import sys

input = sys.stdin.readline

n, sum = list(map(int, input().split()))
ans = 0
coins = []

for _ in range(n):
    coins.append(int(input()))

coins.reverse()

for coin in coins:
    if coin <= sum:
        ans += sum // coin
        sum %= coin

print(ans)
