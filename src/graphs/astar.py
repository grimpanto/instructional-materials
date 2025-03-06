
import collections

# represents an edge
# a type E
# like a struct in C++ with fields u and v 
Edge = collections.namedtuple("Edge", "u v c")

# positions of nodes inside a 10x10 field
pos = {4 : (1, 10),
       1 : (1, 5),
       5 : (1, 1),
       2 : (4, 4),
       3 : (10, 4),
       6 : (10, 1)}

def get_G1():
    V = {1, 2, 3, 4, 5, 6}
    # edges of with corresponding weights (of course, could be computed utilizing the positions
    E = {Edge(1, 2, 2), Edge(2, 3, 5), Edge(3, 6, 3), Edge(3, 5, 11), Edge(4, 1, 4), Edge(5, 6, 8), Edge(5, 1, 3)}
    return (V, E)

G1 = get_G1()

# return the set of adjacent nodes
def adjacent_nodes(G, node):
    res = set()
    for e in G[1]:
        # test if one end of the edges is same as node and the other one
        # is in the set of nodes
        if e.u == node and e.v in G[0]:
            res.add(e.v)
        elif e.v == node and e.u in G[0]:
            res.add(e.u)
    return res


def w(G, s, n):
    for e in G[1]:
        if e.u == s and e.v == n or e.u == n and e.v == s:
            return e.c
    return float("infinity")


import math

def h(u, v):
#    return 0  # uncomment to show advantage of A*
    return math.sqrt((pos[v][0] - pos[u][0]) ** 2 + (pos[v][0] - pos[u][0]) ** 2)


import heapq

# G : graph
# w : costs for each edge
# s : start node
# g : goal node
# h : heuristics functions
def astar(G, w, s, g, h):
    open_list = []
    closed_list = {}  # closed list *and* dedicated parent
    c = {s : 0}  # costs for node

    # open_list consists of (costs, (node, parent))
    # costs: are the estimated costs to the specified node
    # node: the node in question
    # parent: parent of the node
    heapq.heappush(open_list, (0, (s, None)))

    # cnt = 0  # just to show the advantage of A*
    while open_list:
        # get next with minimum estimated costs to goal
        _, f = heapq.heappop(open_list)  # priority does not matter

        if f[0] in closed_list:
            # Oops. Already expanded.
            continue

        # put it in closed_list with associated predecessor
        closed_list[f[0]] = f[1]

        # on target!
        if f[0] == g:
            break

        for n in adjacent_nodes(G, f[0]):
            if n not in closed_list:
                c[n] = c[f[0]] + w(G, f[0], n)  # actual costs for n
                # extend with estimated costs to goal and node
                heapq.heappush(open_list, (c[n] + h(n, g), (n, f[0])))
        # cnt += 1  # just to show the advantage of A*

    # print(cnt)  # just to show the advantage of A*

    # construct path if solution has been found
    path = []
    f = f[0]
    if f == g:
        path.insert(0, f)
        while f and f != s:
            f = closed_list[f]
            path.insert(0, f)

    return path


res = astar(G1, w, 1, 4, h)
print(res)
res = astar(G1, w, 1, 2, h)
print(res)
res = astar(G1, w, 1, 3, h)
print(res)
res = astar(G1, w, 1, 5, h)
print(res)
res = astar(G1, w, 1, 6, h)
print(res)
res = astar(G1, w, 6, 1, h)
print(res)
res = astar(G1, w, 5, 2, h)
print(res)
