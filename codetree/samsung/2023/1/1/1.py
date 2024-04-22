import sys
from collections import deque

input = sys.stdin.readline


def find_attacker(power_board, last_attack_board, n, m, turn_number):
    attacker_power = 5001
    attacker_pos = [-1, -1]
    attacker_last_attack = -1

    for y in range(n):
        for x in range(m):
            if power_board[y][x] == 0:
                continue
            if power_board[y][x] < attacker_power or (
                    power_board[y][x] == attacker_power and (
                    last_attack_board[y][x] > attacker_last_attack or (
                    last_attack_board[y][x] == attacker_last_attack and (
                    y + x > sum(attacker_pos) or (y + x == sum(attacker_pos) and x > attacker_pos[1]))))):
                attacker_power = power_board[y][x]
                attacker_pos = [y, x]
                attacker_last_attack = last_attack_board[y][x]

    # print(attacker_pos)
    power_board[attacker_pos[0]][attacker_pos[1]] += m + n
    last_attack_board[attacker_pos[0]][attacker_pos[1]] = turn_number

    return attacker_pos


def find_target(power_board, last_attack_board, n, m, attacker_pos):
    target_power = -1
    target_pos = [-1, -1]
    target_last_attack = -1

    for y in range(n):
        for x in range(m):
            if power_board[y][x] == 0:
                continue
            if [y, x] == attacker_pos:
                continue
            if power_board[y][x] > target_power or (
                    power_board[y][x] == target_power and (
                    last_attack_board[y][x] < target_last_attack or (
                    last_attack_board[y][x] == target_last_attack and (
                    y + x < sum(target_pos) or (y + x == sum(target_pos) and x < target_pos[1]))))):
                target_power = power_board[y][x]
                target_pos = [y, x]
                target_last_attack = last_attack_board[y][x]

    return target_pos


def get_next_pos(ny, nx, n, m):
    if ny < 0:
        ny = n - 1
    elif ny == n:
        ny = 0
    if nx < 0:
        nx = m - 1
    elif nx == m:
        nx = 0

    return ny, nx


def attack_1(power_board, n, m, attacker_pos, target_pos, should_add_1, num_available):
    q = deque()
    parent = [[None for _ in range(m)] for _ in range(n)]
    parent[attacker_pos[0]][attacker_pos[1]] = (-1, -1)
    q.append((attacker_pos[0], attacker_pos[1], 0))

    can_attack = False
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    min_dist = min(abs(attacker_pos[0] - target_pos[0]), n - abs(attacker_pos[0] - target_pos[0])) + min(
        abs(attacker_pos[1] - target_pos[1]), m - abs(attacker_pos[1] - target_pos[1]))

    while len(q):
        y, x, dist = q.popleft()
        if [y, x] == target_pos:
            can_attack = True
            break
        # if dist == min_dist:
        #     continue
        for next_dir in range(4):
            ny, nx = get_next_pos(y + dy[next_dir], x + dx[next_dir], n, m)
            # print(y, x, ny, nx, dist)
            if power_board[ny][nx] == 0:
                continue
            if parent[ny][nx] is not None:
                continue
            parent[ny][nx] = (y, x)
            q.append((ny, nx, dist + 1))

    if can_attack:
        y, x = target_pos
        power_board[target_pos[0]][target_pos[1]] = max(0, power_board[target_pos[0]][target_pos[1]] - power_board[attacker_pos[0]][attacker_pos[1]])
        if power_board[target_pos[0]][target_pos[1]] == 0:
            num_available -= 1
        while True:
            y, x = parent[y][x]
            if [y, x] == attacker_pos:
                break
            should_add_1[y][x] = False
            power_board[y][x] = max(0, power_board[y][x] - power_board[attacker_pos[0]][attacker_pos[1]] // 2)
            if power_board[y][x] == 0:
                num_available -= 1

    return can_attack, num_available


def attack_2(power_board, n, m, attacker_pos, target_pos, should_add_1, num_available):
    y, x = target_pos
    dy = [-1, -1, -1, 0, 0, 1, 1, 1]
    dx = [-1, 0, 1, -1, 1, -1, 0, 1]

    # print(y, x)
    for next_dir in range(8):
        ny, nx = get_next_pos(y+dy[next_dir], x+dx[next_dir], n, m)
        # print(ny, nx)
        if power_board[ny][nx] == 0:
            continue
        if [ny, nx] == attacker_pos:
            continue
        # print("hihi", power_board[ny][nx], power_board[attacker_pos[0]][attacker_pos[1]])
        # print("haha", ny, nx, attacker_pos[0], attacker_pos[1])
        power_board[ny][nx] = max(0, power_board[ny][nx] - power_board[attacker_pos[0]][attacker_pos[1]] // 2)
        if power_board[ny][nx] == 0:
            num_available -= 1
        should_add_1[ny][nx] = False
    power_board[y][x] = max(0, power_board[y][x] - power_board[attacker_pos[0]][attacker_pos[1]])
    if power_board[y][x] == 0:
        num_available -= 1

    return num_available


def find_max_power(power_board, n, m):
    max_val = -1
    for y in range(n):
        for x in range(m):
            max_val = max(max_val, power_board[y][x])

    return max_val


def solve():
    n, m, k = list(map(int, input().split()))

    power_board = [list(map(int, input().split())) for _ in range(n)]
    last_attack_board = [[0 for _ in range(m)] for _ in range(n)]

    num_available = 0
    for i in range(n):
        for j in range(m):
            if power_board[i][j] > 0:
                num_available += 1

    for turn_number in range(1, k + 1):
        if num_available <= 1:
            break

        should_add_1 = [[True for _ in range(m)] for _ in range(n)]
        attacker_pos = find_attacker(power_board, last_attack_board, n, m, turn_number)
        target_pos = find_target(power_board, last_attack_board, n, m, attacker_pos)
        should_add_1[attacker_pos[0]][attacker_pos[1]] = False
        should_add_1[target_pos[0]][target_pos[1]] = False

        attacked, num_available = attack_1(power_board, n, m, attacker_pos, target_pos, should_add_1, num_available)

        # print("IS ATTACKED? ", attacked)

        if not attacked:
            num_available = attack_2(power_board, n, m, attacker_pos, target_pos, should_add_1, num_available)

        for y in range(n):
            for x in range(m):
                if power_board[y][x] > 0 and should_add_1[y][x]:
                    power_board[y][x] += 1

        # print('--------------------')
        # for y in range(n):
        #     for x in range(m):
        #         print(power_board[y][x], end =  ' ')
        #     print()
        # print(num_available)
        # print('--------------------')

    print(find_max_power(power_board, n, m))


solve()
