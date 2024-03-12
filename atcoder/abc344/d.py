import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

str = input().strip()
N = int(input())
bags = []
num_items_in_bag = []

dp = []
for _ in range(N):
    s = input().split()
    num_items_in_bag.append(int(s[0]))
    bags.append(sorted(s[1:]))
    dp.append([-1] * len(str))


def bt(bag_id, pos):
    if pos == len(str):
        return 0

    if bag_id == N:
        return -2

    if dp[bag_id][pos] != -1:
        return dp[bag_id][pos]

    for i in range(len(bags[bag_id])):
        el = bags[bag_id][i]
        if len(str) - pos < len(el):
            continue

        if str[pos : pos + len(el)] == el:
            nxtVal = bt(bag_id + 1, pos + len(el))
            if nxtVal == -2:
                continue
            if dp[bag_id][pos] == -1:
                dp[bag_id][pos] = 1 + nxtVal
            else:
                dp[bag_id][pos] = min(dp[bag_id][pos], 1 + nxtVal)

    nxtVal = bt(bag_id + 1, pos)
    if nxtVal != -2:
        if dp[bag_id][pos] == -1:
            dp[bag_id][pos] = nxtVal
        else:
            dp[bag_id][pos] = min(dp[bag_id][pos], nxtVal)

    if dp[bag_id][pos] == -1:
        dp[bag_id][pos] = -2

    return dp[bag_id][pos]


ans = bt(0, 0)
if ans == -2:
    print(-1)
else:
    print(ans)
