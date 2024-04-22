import sys

input = sys.stdin.readline


def fill_child(cur, child, authority, adj):
    if cur > 0:
        child[cur][min(authority[cur], 40)] += 1
    if adj[cur][0] == -1 and adj[cur][1] == -1:
        return
    for i in [0, 1]:
        if adj[cur][i] != -1:
            fill_child(adj[cur][i], child, authority, adj)
            for j in range(0, 40):
                child[cur][j] += child[adj[cur][i]][j + 1]


def switch(should_turn_on, is_on, child, cur, switch_node, minus, parent):
    for i in range(minus, 41):
        child[cur][i - minus] += child[switch_node][i] if should_turn_on else -child[switch_node][i]
    if is_on[cur] and parent[cur] != cur:
        switch(should_turn_on, is_on, child, parent[cur], switch_node, minus + 1, parent)


def remove_authority(cur, parent, child, authority, is_on):
    child[cur][authority] -= 1
    if authority > 0 and parent[cur] != cur and is_on[cur]:
        remove_authority(parent[cur], parent, child, authority - 1, is_on)


def add_authority(cur, parent, child, authority, is_on):
    child[cur][authority] += 1
    if authority > 0 and parent[cur] != cur and is_on[cur]:
        add_authority(parent[cur], parent, child, authority - 1, is_on)


def solve():
    n, q = list(map(int, input().split()))
    tmp = list(map(int, input().split()))

    parent = [0] + tmp[1:n + 1]
    authority = [0] + tmp[n + 1:]
    child = [[0 for _ in range(41)] for _ in range(n + 1)]
    adj = [[-1, -1] for _ in range(n + 1)]
    is_on = [True for _ in range(n + 1)]

    for i in range(1, n + 1):
        u, p = i, parent[i]
        if adj[p][0] != -1:
            adj[p][1] = u
        else:
            adj[p][0] = u

    for i in range(len(authority)):
        authority[i] = min(40, authority[i])

    fill_child(0, child, authority, adj)

    q -= 1

    while q > 0:
        q -= 1
        cmds = list(map(int, input().split()))

        if cmds[0] == 200:
            switch_node = cmds[1]
            is_on[switch_node] = False if is_on[switch_node] else True
            switch(is_on[switch_node], is_on, child, parent[switch_node], switch_node, 1, parent)
        if cmds[0] == 300:
            switch_node, power = cmds[1:]
            power = min(40, power)
            remove_authority(switch_node, parent, child, authority[switch_node], is_on)
            authority[switch_node] = power
            add_authority(switch_node, parent, child, power, is_on)
        if cmds[0] == 400:
            u1, u2 = cmds[1:]
            if is_on[u1]:
                switch(False, is_on, child, parent[u1], u1, 1, parent)
            if is_on[u2]:
                switch(False, is_on, child, parent[u2], u2, 1, parent)
            parent[u1], parent[u2] = parent[u2], parent[u1]
            if is_on[u1]:
                switch(True, is_on, child, parent[u1], u1, 1, parent)
            if is_on[u2]:
                switch(True, is_on, child, parent[u2], u2, 1, parent)
        if cmds[0] == 500:
            u = cmds[1]
            print(sum(child[u]) - 1)

        # print("----------------------")
        # print(cmds)
        # for i, el in enumerate(child):
        #     print(i, el)


solve()
