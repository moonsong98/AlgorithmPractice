n = int(input())

arr = []

ans = 0

for _ in range(n):
    arr = [int(x) for x in input().split()]
    ans += sum(arr) >= 2

print(ans)
