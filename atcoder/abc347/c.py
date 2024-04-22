import sys

input = sys.stdin.readline

n, a, b = list(map(int, input().split()))
arr = list(map(int, input().split()))

num_days = a + b
bag = set([el % num_days for el in arr])
bag = list(bag)
bag.sort()

ans = bag[-1] - bag[0] + 1 <= a

for i in range(len(bag) - 1):
    if bag[i + 1] - bag[i] - 1 >= b:
        ans = True

print("Yes" if ans else "No")
