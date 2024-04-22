import sys
import itertools

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n = int(input())
adj = [list(map(int, input().split())) for _ in range(n)]

all_people = list(range(n))

ans = int(1e9)

for teamA in itertools.combinations(all_people, n // 2):
    teamB = list(filter(lambda x: x not in teamA, all_people))

    s_a, s_b = 0, 0
    for i in range(n // 2):
        for j in range(i + 1, n // 2):
            s_a += adj[teamA[i]][teamA[j]]
            s_a += adj[teamA[j]][teamA[i]]
            s_b += adj[teamB[i]][teamB[j]]
            s_b += adj[teamB[j]][teamB[i]]

    ans = min(ans, abs(s_a - s_b))

print(ans)
