import sys

input = sys.stdin.readline

s = input().strip()

ans = 0
for length in range(1, len(s) + 1):
    bag = set()
    for start_idx in range(0, len(s) - length + 1):
        ss = s[start_idx : start_idx + length]
        if ss not in bag:
            ans += 1
            bag.add(ss)
print(ans)
