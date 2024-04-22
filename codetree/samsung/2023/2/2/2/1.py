import sys

input = sys.stdin.readline


def check_is_out(y, x, n):
    return not (1 <= y and y <= n and 1 <= x and x <= n)


def check_is_game_end(num_santas, dead):
    return num_santas == len(dead)


def release_stunned(step, step_stunned, stunned):
    for i, el in enumerate(step_stunned):
        if el == -1:
            continue
        if el + 2 == step:
            stunned.remove(i)


def add_score_after_step_end(dead, scores, num_santas):
    for santa in range(1, num_santas + 1):
        if santa not in dead:
            scores[santa] += 1


def calc_dist(pos1, pos2):
    return (pos1[0] - pos2[0]) ** 2 + (pos1[1] - pos2[1]) ** 2


def handle_crash(
    is_crash_by_rudolph,
    c,
    d,
    dy,
    dx,
    n,
    pos_santas,
    crashed_santa,
    board,
    dead,
    stunned,
    step_stunned,
    step,
    scores,
):
    board[pos_santas[crashed_santa][0]][pos_santas[crashed_santa][1]] = None
    pos_santas[crashed_santa][0] += c * dy if is_crash_by_rudolph else -d * dy
    pos_santas[crashed_santa][1] += c * dx if is_crash_by_rudolph else -d * dx
    scores[crashed_santa] += c if is_crash_by_rudolph else d

    if check_is_out(pos_santas[crashed_santa][0], pos_santas[crashed_santa][1], n):
        dead.add(crashed_santa)
        return

    stunned.add(crashed_santa)
    step_stunned[crashed_santa] = step

    if board[pos_santas[crashed_santa][0]][pos_santas[crashed_santa][1]] != None:
        handle_interaction(
            board,
            pos_santas,
            crashed_santa,
            dy if is_crash_by_rudolph else -dy,
            dx if is_crash_by_rudolph else -dx,
            n,
            dead,
        )
    else:
        board[pos_santas[crashed_santa][0]][
            pos_santas[crashed_santa][1]
        ] = crashed_santa


def handle_interaction(board, pos_santas, crashed_santa, dy, dx, n, dead):
    while True:
        if check_is_out(pos_santas[crashed_santa][0], pos_santas[crashed_santa][1], n):
            dead.add(crashed_santa)
            break
        if board[pos_santas[crashed_santa][0]][pos_santas[crashed_santa][1]] == None:
            board[pos_santas[crashed_santa][0]][
                pos_santas[crashed_santa][1]
            ] = crashed_santa
            break

        new_crashed_santa = board[pos_santas[crashed_santa][0]][
            pos_santas[crashed_santa][1]
        ]
        board[pos_santas[crashed_santa][0]][
            pos_santas[crashed_santa][1]
        ] = crashed_santa
        crashed_santa = new_crashed_santa
        pos_santas[crashed_santa][0] += dy
        pos_santas[crashed_santa][1] += dx


def move_rudolph(
    dead,
    pos_rudolph,
    pos_santas,
    num_santas,
    n,
    c,
    d,
    board,
    stunned,
    step_stunned,
    step,
    scores,
):
    dy = [0, 1, 0, -1, 1, 1, -1, -1]
    dx = [1, 0, -1, 0, 1, -1, 1, -1]

    min_dist, sn, sy, sx = -1, -1, -1, -1

    # Find closest rudolph
    for santa in range(1, num_santas + 1):
        if santa in dead:
            continue

        dist = calc_dist(pos_rudolph, pos_santas[santa])
        if (
            min_dist == -1
            or dist < min_dist
            or (
                min_dist == dist
                and (
                    pos_santas[santa][0] > sy
                    or (pos_santas[santa][0] == sy and pos_santas[santa][1] > sx)
                )
            )
        ):
            min_dist = dist
            sn = santa
            sy, sx = pos_santas[santa]

    # Find direction
    opt_direction = -1
    min_dist = -1
    for i in range(8):
        ny, nx = pos_rudolph[0] + dy[i], pos_rudolph[1] + dx[i]
        if check_is_out(ny, nx, n):
            continue
        dist = calc_dist([ny, nx], [sy, sx])
        if min_dist == -1 or dist < min_dist:
            min_dist = dist
            opt_direction = i

    # Move Rudolph
    pos_rudolph[0] += dy[opt_direction]
    pos_rudolph[1] += dx[opt_direction]

    # Crashed
    if pos_rudolph[0] == sy and pos_rudolph[1] == sx:
        handle_crash(
            True,
            c,
            d,
            dy[opt_direction],
            dx[opt_direction],
            n,
            pos_santas,
            sn,
            board,
            dead,
            stunned,
            step_stunned,
            step,
            scores,
        )


def move_santa(
    dead,
    stunned,
    board,
    pos_rudolph,
    pos_santas,
    num_santas,
    n,
    c,
    d,
    step_stunned,
    step,
    scores,
):
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    for santa in range(1, num_santas + 1):
        if santa in dead or santa in stunned:
            continue

        min_dist, opt_direction = calc_dist(pos_rudolph, pos_santas[santa]), -1
        for i in range(4):
            ny, nx = pos_santas[santa][0] + dy[i], pos_santas[santa][1] + dx[i]
            if check_is_out(ny, nx, n) or board[ny][nx] != None:
                continue
            dist = calc_dist(pos_rudolph, [ny, nx])
            if dist < min_dist:
                min_dist = dist
                opt_direction = i

        if opt_direction == -1:
            continue

        board[pos_santas[santa][0]][pos_santas[santa][1]] = None
        pos_santas[santa][0] += dy[opt_direction]
        pos_santas[santa][1] += dx[opt_direction]
        board[pos_santas[santa][0]][pos_santas[santa][1]] = santa

        if (
            pos_santas[santa][0] == pos_rudolph[0]
            and pos_santas[santa][1] == pos_rudolph[1]
        ):
            handle_crash(
                False,
                c,
                d,
                dy[opt_direction],
                dx[opt_direction],
                n,
                pos_santas,
                santa,
                board,
                dead,
                stunned,
                step_stunned,
                step,
                scores,
            )


def solve():
    n, m, num_santas, c, d = list(map(int, input().split()))
    board = [[None for _ in range(n + 1)] for _ in range(n + 1)]
    pos_rudolph = list(map(int, input().split()))
    pos_santas = [None for _ in range(num_santas + 1)]
    for _ in range(num_santas):
        sn, y, x = list(map(int, input().split()))
        pos_santas[sn] = [y, x]
        board[y][x] = sn
    scores = [0 for _ in range(num_santas + 1)]
    step_stunned = [-1 for _ in range(num_santas + 1)]
    stunned = set()
    dead = set()

    for step in range(m):
        release_stunned(step, step_stunned, stunned)

        move_rudolph(
            dead,
            pos_rudolph,
            pos_santas,
            num_santas,
            n,
            c,
            d,
            board,
            stunned,
            step_stunned,
            step,
            scores,
        )

        move_santa(
            dead,
            stunned,
            board,
            pos_rudolph,
            pos_santas,
            num_santas,
            n,
            c,
            d,
            step_stunned,
            step,
            scores,
        )

        if check_is_game_end(num_santas, dead):
            break
        add_score_after_step_end(dead, scores, num_santas)

    print(*scores[1:])


solve()
