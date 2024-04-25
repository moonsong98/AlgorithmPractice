import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

s = sum(arr) + 8 * (len(arr) - 1)

print(s // 24, s % 24)
