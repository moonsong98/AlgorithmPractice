import sys
import heapq

input = sys.stdin.readline

n, m = list(map(int, input().split()))

preference = [[] for _ in range(2 * 10**6 + 1)]

for i in range(n):
    amt, *foods = list(map(int, input().split()))
    for food in foods:
        heapq.heappush(preference[food], i)

score = [0 for _ in range(n)]
for el in list(map(int, input().split())):
    if len(preference[el]) > 0:
        score[preference[el][0]] += 1
        heapq.heappop(preference[el])

print(*score)
