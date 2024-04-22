import sys
import heapq

input = sys.stdin.readline


def make(time, pos, name, pending, customer_pos, onboard, L):
    time = int(time)
    pos = int(pos)

    if name in customer_pos:
        heapq.heappush(onboard, ((customer_pos[name] - pos) % L + time, name))
    else:
        if name not in pending:
            pending[name] = [(time, pos)]
        else:
            pending[name].append((time, pos))


def seat(time, pos, name, amt, pending, customer_pos, on_board, L, left):
    time = int(time)
    pos = int(pos)
    amt = int(amt)

    left[name] = amt
    customer_pos[name] = pos
    if name in pending:
        for pen_time, pen_pos in pending[name]:
            cur_pos = (pen_pos + time - pen_time) % L
            heapq.heappush(on_board, ((pos - cur_pos) % L + time, name))


def resolve(time, on_board, left, num_user, num_item):
    time = int(time)
    while len(on_board):
        if on_board[0][0] > time:
            break
        left[on_board[0][1]] -= 1
        if left[on_board[0][1]] == 0:
            num_user -= 1
        heapq.heappop(on_board)
        num_item -= 1

    return num_user, num_item


def solve():
    l, q = list(map(int, input().split()))

    pending = dict()  # name: [(time, pos)]
    customer_pos = dict()  # name: pos
    left = dict()  # name: amt
    on_board = []  # [(removal_time, name)]

    num_user, num_item = 0, 0

    for _ in range(q):
        cmds = input().split()
        cmd = cmds[0]

        if cmd == "100":
            make(*cmds[1:], pending, customer_pos, on_board, l)
            num_item += 1

        if cmd == "200":
            seat(*cmds[1:], pending, customer_pos, on_board, l, left)
            num_user += 1

        if cmd == "300":
            num_user, num_item = resolve(*cmds[1:], on_board, left, num_user, num_item)
            print(num_user, num_item)


solve()
