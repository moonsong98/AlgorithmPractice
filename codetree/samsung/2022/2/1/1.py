import sys
import heapq

input = sys.stdin.readline

dir_y = [-1, 0, 1, 0]
dir_x = [0, 1, 0, -1]


class Player:
    gun = 0

    def __init__(self, ability, direction, player_num):
        self.ability = ability
        self.direction = direction
        self.player_num = player_num


def move(player_num, gun_board, player_board, player_pos, score, n):
    y, x = player_pos[player_num]
    player = player_board[y][x]

    ny, nx = y + dir_y[player.direction], x + dir_x[player.direction]
    if not (0 <= ny < n and 0 <= nx < n):
        player.direction = (player.direction + 2) % 4
        ny, nx = y + dir_y[player.direction], x + dir_x[player.direction]

    player_board[y][x] = None
    if player_board[ny][nx] is None:
        # print("hi", player_num)
        if len(gun_board[ny][nx]):
            if -gun_board[ny][nx][0] > player.gun:
                if player.gun > 0:
                    heapq.heappush(gun_board[ny][nx], -player.gun)
                player.gun = -gun_board[ny][nx][0]
                heapq.heappop(gun_board[ny][nx])
        player_board[ny][nx] = player
        player_pos[player_num] = [ny, nx]
    else:
        # print("hi2", player_num)
        opponent = player_board[ny][nx]
        player_board[ny][nx] = None
        if player.ability + player.gun > opponent.ability + opponent.gun:
            winner, loser = player, opponent
        elif player.ability + player.gun < opponent.ability + opponent.gun:
            winner, loser = opponent, player
        else:
            if player.ability < opponent.ability:
                winner, loser = opponent, player
            else:
                winner, loser = player, opponent

        score[winner.player_num] += (winner.ability + winner.gun - loser.ability - loser.gun)
        if loser.gun > 0:
            heapq.heappush(gun_board[ny][nx], -loser.gun)
            loser.gun = 0

        for next_dir in range(4):
            loser_ny, loser_nx = ny + dir_y[(loser.direction + next_dir) % 4], nx + dir_x[
                (loser.direction + next_dir) % 4]
            if not (0 <= loser_ny < n and 0 <= loser_nx < n):
                continue
            if player_board[loser_ny][loser_nx] is not None:
                continue

            if len(gun_board[loser_ny][loser_nx]):
                loser.gun = -gun_board[loser_ny][loser_nx][0]
                heapq.heappop(gun_board[loser_ny][loser_nx])

            # print("loser old direction: ", loser.direction, loser.player_num)
            loser.direction = (loser.direction+next_dir) % 4
            # print("loser new direction: ", loser.direction, loser.player_num)
            player_board[loser_ny][loser_nx] = loser
            player_pos[loser.player_num] = [loser_ny, loser_nx]
            break

        if len(gun_board[ny][nx]) and winner.gun < -gun_board[ny][nx][0]:
            if winner.gun > 0:
                heapq.heappush(gun_board[ny][nx], -winner.gun)
            winner.gun = -gun_board[ny][nx][0]
            heapq.heappop(gun_board[ny][nx])

        player_board[ny][nx] = winner
        player_pos[winner.player_num] = [ny, nx]


def solve():
    n, m, k = list(map(int, input().split()))
    init_board = [list(map(int, input().split())) for _ in range(n)]
    gun_board = [[[] for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if init_board[i][j] > 0:
                heapq.heappush(gun_board[i][j], -init_board[i][j])
    player_board = [[None for _ in range(n)] for _ in range(n)]
    player_pos = []
    score = [0 for _ in range(m)]

    for i in range(m):
        y, x, d, s = list(map(int, input().split()))
        y -= 1
        x -= 1
        player_pos.append((y, x))
        player = Player(s, d, i)
        player_board[y][x] = player

    for turn in range(1, k+1):
        for player_num in range(m):
            move(player_num, gun_board, player_board, player_pos, score, n)
        # print(f"========={turn}===========")
        # for i in range(n):
        #     for j in range(n):
        #         print(gun_board[i][j], end = ' ')
        #     print()
        #
        # print("====================")
        # for i in range(n):
        #     for j in range(n):
        #         print(None if player_board[i][j] is None else (player_board[i][j].player_num, player_board[i][j].gun, player_board[i][j].ability, player_board[i][j].direction), end = ' ')
        #     print()
        # print(*score)

    print(*score)

    # for i in range(n):
    #     for j in range(n):
    #         print(gun_board[i][j], end = ' ')
    #     print()
    #
    # print("====================")
    # for i in range(n):
    #     for j in range(n):
    #         print(None if player_board[i][j] is None else (player_board[i][j].player_num, player_board[i][j].gun), end = ' ')
    #     print()


solve()
