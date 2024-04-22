import sys

input = sys.stdin.readline

n = int(input())
points = [list(map(int, input().split())) for _ in range(n)]


def calc_dist(p1, p2):
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2


for i in range(n):
    min_dist = -1
    ans = -1
    for j in range(n):
        if i == j:
            continue
        dist = calc_dist(points[i], points[j])
        if dist > min_dist:
            min_dist = dist
            ans = j + 1

    print(ans)
