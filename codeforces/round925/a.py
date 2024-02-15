import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n = int(input())

for _ in range(n):
    m = int(input())
    ans = []
    if m > 52:
        ans.append(chr(ord('a') + m - 53))
        ans.append('zz')
    elif m > 27:
        ans.append('a')
        ans.append(chr(ord('a') + m - 28))
        ans.append('z')
    else:
        ans.append('aa')
        ans.append(chr(ord('a') + m-3))
    for ch in ans:
        print(ch, end='')
    print()




        
