import sys
import heapq

input = sys.stdin.readline


class Url:
    def __init__(self):
        self.start = -1
        self.end = -1
        self.is_in_machine = False
        self.is_in_queue = dict()  # by problem number


def init(num_machines, url_0, d2i, url_info, waiting_queue):
    machines = [-1 for _ in range(num_machines)]

    domain, problem_number = url_0.split('/')
    problem_number = int(problem_number)

    d2i[domain] = 0
    url_info.append(Url())

    heapq.heappush(waiting_queue, (1, 0, 0, problem_number))
    url_info[0].is_in_queue[problem_number] = True

    return machines


def handle_request(time, priority, url, url_info, waiting_queue, d2i):
    domain, pn = url.split('/')

    domain_id = -1
    if domain not in d2i:
        domain_id = len(url_info)
        d2i[domain] = domain_id
        url_info.append(Url())
    else:
        domain_id = d2i[domain]

    if pn not in url_info[domain_id].is_in_queue:
        url_info[domain_id].is_in_queue[pn] = False

    if url_info[domain_id].is_in_queue[pn]:
        return

    url_info[domain_id].is_in_queue[pn] = True
    heapq.heappush(waiting_queue, (priority, time, domain_id, pn))


def handle_try(try_time, url_info, waiting_queue, machines):
    impossible_queue = []

    next_machine = -1
    for i in range(len(machines)):
        if machines[i] == -1:
            next_machine = i
            break
    if next_machine == -1:
        return

    while len(waiting_queue) > 0:
        priority, time, domain_id, pn = heapq.heappop(waiting_queue)
        if url_info[domain_id].is_in_machine:
            impossible_queue.append((priority, time, domain_id, pn))
            continue

        if url_info[domain_id].start != -1 and url_info[domain_id].start + (
                url_info[domain_id].end - url_info[domain_id].start) * 3 >= try_time:
            impossible_queue.append((priority, time, domain_id, pn))
            continue

        machines[next_machine] = domain_id
        url_info[domain_id].start = try_time
        url_info[domain_id].is_in_machine = True
        url_info[domain_id].is_in_queue[pn] = False
        break

    for el in impossible_queue:
        heapq.heappush(waiting_queue, el)


def handle_end(end_time, machine_id, machines, url_info):
    if machines[machine_id] == -1:
        return

    domain_id = machines[machine_id]
    machines[machine_id] = -1
    url_info[domain_id].is_in_machine = False
    url_info[domain_id].end = end_time

    # print(domain, url_info[domain].start, url_info[domain].end)


def solve():
    num_queries = int(input())
    waiting_queue = []
    url_info = []
    d2i = dict()
    machines = []

    for _ in range(num_queries):
        # print(waiting_queue
        # print(machines)
        cmds = input().split()
        if cmds[0] == '100':
            num_machines = int(cmds[1])
            url_0 = cmds[2]
            machines = init(num_machines, url_0, d2i, url_info, waiting_queue)
        if cmds[0] == '200':
            request_time, priority = list(map(int, cmds[1:3]))
            url = cmds[3]
            handle_request(request_time, priority, url, url_info, waiting_queue, d2i)
        if cmds[0] == '300':
            try_time = int(cmds[1])
            handle_try(try_time, url_info, waiting_queue, machines)
        if cmds[0] == '400':
            end_time, machine_id = list(map(int, cmds[1:3]))
            machine_id -= 1
            handle_end(end_time, machine_id, machines, url_info)
        if cmds[0] == '500':
            # print("ANS:", len(waiting_queue))
            print(len(waiting_queue))


solve()
