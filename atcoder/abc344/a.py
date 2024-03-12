import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

str = input().strip()

strs = str.split("|")
print(strs[0] + strs[2])
