
def anyitem(iterable):
    try:
        return next(iter(iterable))
    except StopIteration:
        return None


# ???
def anyitem_in_set(iterable, s):
    for item in iterable:
        if item in s:
            return item
    return None

    
def get_G1():
    v = {1,2,3,4,5,6}
    e = {(1, 2), (2, 3), (3, 4), (4, 5), (5, 6), (6, 1)}
    return (v, e)


def get_G2():
    v = {1,2,3,4,5,6}
    e = {(1, 2), (2, 3), (3, 1), (4, 5), (5, 6), (6, 4)}
    return (v, e)


def get_G3():
    v = {1,2,3,4,5}
    e = {(1, 2), (1, 3), (2, 3), (3, 4), (3, 5), (5, 4)}
    return (v, e)


def adjacent_nodes(g, node):
    res = set()
    for edge in g[1]:
        # test if one end of the edge is same as node and other one
        # is in set of nodes
        if edge[0] == node and edge[1] in g[0]:
            res.add(edge[1])
        elif edge[1] == node and edge[0] in g[0]:
            res.add(edge[0])
    return res


def incident_edges(g, node):
    res = set()
    for edge in g[1]:
        if edge[0] == node or edge[1] == node:
            res.add(edge)
    return res


def is_connected(g):
    agenda = [anyitem(g[0])]  # add start node to empty agenda
    marked = set()  # used to mark nodes

    while agenda:
        node = agenda.pop(0)
        marked.add(node)
        for adjacent_node in adjacent_nodes(g, node):
            if adjacent_node not in marked:
                agenda.append(adjacent_node)

    return marked == g[0]


print(is_connected(get_G1()))
print(is_connected(get_G2()))
print(is_connected(get_G3()))


def find_cycle(g, v0):
    cycle = []
    free_edges = g[1].copy()
    next_node = v0
    while True:
        next_edge = anyitem(incident_edges((g[0], free_edges), next_node))
        if next_node == next_edge[0]:
            next_node = next_edge[1]
        else:
            next_node = next_edge[0]
        cycle.append(next_edge)
        free_edges.remove(next_edge)
        if next_node == v0:
            break
    return cycle


def is_euler(g, cycle):
    nodes = set()
    for edge in cycle:
        nodes.add(edge[0])
        nodes.add(edge[1])
    return nodes == g[0]


cycle = find_cycle(get_G1(), 1)
print(cycle)
print(is_euler(get_G1(), cycle))

cycle = find_cycle(get_G2(), 1)
print(cycle)
print(is_euler(get_G2(), cycle))

cycle = find_cycle(get_G3(), 1)
print(cycle)
print(is_euler(get_G3(), cycle))

cycle = find_cycle(get_G3(), 3)
print(cycle)
print(is_euler(get_G3(), cycle))

cycle = find_cycle(get_G3(), 2)
print(cycle)
print(is_euler(get_G3(), cycle))

def hierholzer(g):
    v0 = anyitem(g[0])  # start node
    cycle = find_cycle(g, v0)
    visited_edges = set(cycle)
    while not is_euler(g, cycle):
        pass
