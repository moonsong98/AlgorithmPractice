import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

T = int(input())

def check(x, y):
    print(f"? {x} {y}")
    sys.stdout.flush()
    dist = int(input())
    if dist == 0:
        print(f"! {x} {y}")
        sys.stdout.flush()
        return True, dist
    return False, dist


while T:
    T -= 1
    m, n = map(int, input().split())

    is_match, dist = check(1, 1)
    
    if is_match:
        continue

    dx = min(m - 1, dist)
    dy = min(n - 1, dist)

    is_match, dist1 = check(1 + dx, 1 + dist - dx)

    if is_match:
        continue

    is_match, dist2 = check(1 + dist - dy, 1 + dy)

    if is_match:
        continue

    is_match, _ = check(1 + dx - dist1//2, 1 + dist - dx + dist1//2)

    if is_match:
        continue

    print(f"! {1 + dist - dy + dist2//2} {1 + dy - dist2//2}")
    sys.stdout.flush()
    