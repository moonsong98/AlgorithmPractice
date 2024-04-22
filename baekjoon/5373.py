import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))


def spin_U(cube, dir):
    def assign(a, b, c, d):
        for i in range(3):
            cube[a][b][i] = cube[c][d][i]

    if dir == "+":
        tmp = cube[2][0][:]
        assign(2, 0, 5, 0)
        assign(5, 0, 3, 0)
        assign(3, 0, 4, 0)
        for i in range(3):
            cube[4][0][i] = tmp[i]
    else:
        tmp = cube[2][0][:]
        assign(2, 0, 4, 0)
        assign(4, 0, 3, 0)
        assign(3, 0, 5, 0)
        for i in range(3):
            cube[5][0][i] = tmp[i]


def spin_D(cube, dir):
    def assign(a, b, c, d):
        for i in range(3):
            cube[a][b][i] = cube[c][d][i]

    if dir == "+":
        tmp = cube[2][2][:]
        assign(2, 2, 4, 2)
        assign(4, 2, 3, 2)
        assign(3, 2, 5, 2)
        for i in range(3):
            cube[5][2][i] = tmp[i]
    else:
        tmp = cube[2][2][:]
        assign(2, 2, 5, 2)
        assign(5, 2, 3, 2)
        assign(3, 2, 4, 2)
        for i in range(3):
            cube[4][2][i] = tmp[i]


def spin_F(cube, dir):
    def assign_1(a, b, c, d):
        for i in range(3):
            cube[a][b][i] = cube[c][i][d]

    def assign_2(a, b, c, d):
        for i in range(3):
            cube[a][i][b] = cube[c][d][i]

    if dir == "+":
        tmp = cube[0][2][:]
        assign_1(0, 2, 4, 2)
        assign_2(4, 2, 1, 0)
        assign_1(1, 0, 5, 0)
        for i in range(3):
            cube[5][i][0] = tmp[i]
    if dir == "-":
        tmp = cube[0][2][:]
        assign_1(0, 2, 5, 0)
        assign_2(5, 0, 1, 0)
        assign_1(1, 0, 4, 2)
        for i in range(3):
            cube[4][i][2] = tmp[i]


def spin_B(cube, dir):
    def assign_1(a, b, c, d):
        for i in range(3):
            cube[a][b][i] = cube[c][i][d]

    def assign_2(a, b, c, d):
        for i in range(3):
            cube[a][i][b] = cube[c][d][i]

    if dir == "+":
        tmp = cube[0][0][:]
        assign_1(0, 0, 5, 2)
        assign_2(5, 2, 1, 2)
        assign_1(1, 2, 4, 0)
        for i in range(3):
            cube[4][i][0] = tmp[i]
    if dir == "-":
        tmp = cube[0][0][:]
        assign_1(0, 0, 4, 0)
        assign_2(4, 0, 1, 2)
        assign_1(1, 2, 5, 2)
        for i in range(3):
            cube[5][i][2] = tmp[i]


def spin_L(cube, dir):
    def assign(a, b, c, d):
        for i in range(3):
            cube[a][i][b] = cube[c][2 - i][d]

    if dir == "+":
        tmp = cube[0][:][0]
        assign(0, 0, 3, 0)
        assign(3, 0, 1, 0)
        assign(1, 0, 2, 0)
        for i in range(3):
            cube[2][i][0] = tmp[2 - i]
    if dir == "-":
        tmp = cube[0][:][0]
        assign(0, 0, 2, 0)
        assign(2, 0, 1, 0)
        assign(1, 0, 3, 0)
        for i in range(3):
            cube[3][i][0] = tmp[2 - i]


def spin_R(cube, dir):
    def assign(a, b, c, d):
        for i in range(3):
            cube[a][i][b] = cube[c][i][d]

    if dir == "+":
        tmp = cube[0][:][0]
        assign(0, 2, 2, 2)
        assign(2, 2, 1, 2)
        assign(1, 2, 3, 2)
        for i in range(3):
            cube[3][i][2] = tmp[i]
    if dir == "-":
        tmp = cube[0][:][0]
        assign(0, 2, 3, 2)
        assign(3, 2, 1, 2)
        assign(1, 2, 2, 2)
        for i in range(3):
            cube[2][i][2] = tmp[i]


def spin(cube, face, dir):
    if face == "U":
        spin_U(cube, dir)
    if face == "D":
        spin_D(cube, dir)
    if face == "F":
        spin_F(cube, dir)
    if face == "B":
        spin_B(cube, dir)
    if face == "L":
        spin_L(cube, dir)
    if face == "R":
        spin_R(cube, dir)


# U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면
def solution():
    t = int(input())

    for j in range(t):
        n = int(input())
        cmds = input().split()
        cube = []
        colors = ["w", "y", "r", "o", "g", "b"]

        for i in range(6):
            cube.append([[colors[i]] * 3 for _ in range(3)])

        for face, dir in cmds:
            spin(cube, face, dir)

        print(f"{j+1}th test")
        for i in range(3):
            for j in range(3):
                print(cube[0][i][j], end="")
            print()


solution()
