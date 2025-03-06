# ko

import collections

from graphviz import Graph

def build_dot_graph(G, name, constraint='false'):
    dot = Graph(name)
    i = 1
    for v in G[0]:
        dot.node(str(i), str(i))
        i += 1
    for e in G[1]:
        dot.edge(str(e.u), str(e.v), constraint=constraint)
        
    dot.render(name)

# represents an edge
# a type E
# like a struct in C++ with fields u and v 
Edge = collections.namedtuple("Edge", "u v")

# returns an arbitrary item of the iterable
def anyitem(iterable):
    try:
        return next(iter(iterable))
    except StopIteration:
        return None

# just to define and to return the graph G1
def get_G1():
    V = {1, 2, 3, 4, 5, 6}
    E = {Edge(1, 2), Edge(2, 3), Edge(3, 4), Edge(4, 5), Edge(5, 6), Edge(6, 1)}
    return (V, E)

# same for G2
def get_G2():
    V = {1, 2, 3, 4, 5, 6}
    E = {Edge(1, 2), Edge(2, 3), Edge(3, 1), Edge(4, 5), Edge(5, 6), Edge(6, 4)}
    return (V, E)


# same for G3
def get_G3():
    V = {1, 2, 3, 4, 5}
    E = {Edge(1, 2), Edge(1, 3), Edge(2, 3), Edge(3, 4), Edge(3, 5), Edge(5, 4)}
    return (V, E)

G1 = get_G1()
G2 = get_G2()
G3 = get_G3()

# generate nice representations of the graphs
build_dot_graph(G1, "G1")
build_dot_graph(G2, "G2")
build_dot_graph(G3, "G3")


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


print("Benachbarte Knoten von 1 in G1:", adjacent_nodes(G1, 1))
print("Benachbarte Knoten von 2 in G1:", adjacent_nodes(G1, 2))


# return the set of incident edges of given node
def incident_edges(G, node):
    res = set()
    for e in G[1]:
        for n in e:
            if n == node:
                res.add(e)
    return res


print("incident edges of node 1 in G1: ", incident_edges(G1, 1))
print("incident edges of node 1 in G2: ", incident_edges(G2, 1))


# test if the graph is connected
def is_connected(G):
    agenda = [anyitem(G[0])]  # add start node to empty agenda
    marked = set()  # used to mark nodes

    while agenda:
        node = agenda.pop(0)
        marked.add(node)
        for other in adjacent_nodes(G, node):
            if other not in marked:
                agenda.append(other)

    return marked == G[0]


print("G1 is connected:", is_connected(G1))
print("G2 is connected:", is_connected(G2))
print("G3 is connected:", is_connected(G3))


# find cycle in g starting at v0
def find_cycle(g, v0):
    cycle = []
    free_edges = g[1].copy()
    next_node = v0
    while True:
        next_edge = anyitem(incident_edges((g[0], free_edges), next_node))
        nodes_iter = iter(next_edge)
        tmp = next(nodes_iter)
        if tmp == next_node:
            next_node = next(nodes_iter)
        else:
            next_node = tmp
        cycle.append(next_edge)
        free_edges.remove(next_edge)
        if next_node == v0:
            break
    return cycle


# test if cycle is an euler cycle
def is_euler(g, cycle):
    nodes = set()
    for edge in cycle:
        for node in edge:
            nodes.add(node)
    return nodes == g[0]


cycle = find_cycle(G1, 1)
print("cycle of G1 starting at 1:", cycle)
print("cycle is an euler one:", is_euler(G1, cycle))

cycle = find_cycle(G2, 1)
print("cycle of G2 starting at 1:", cycle)
print("cycle is an euler one:", is_euler(G2, cycle))

cycle = find_cycle(G3, 1)
print("cycle of G3 starting at 1:", cycle)
print("cycle is an euler one:", is_euler(G3, cycle))

cycle = find_cycle(G3, 3)
print("cycle of G3 starting at 3:", cycle)
print("cycle is an euler one:", is_euler(G3, cycle))

cycle = find_cycle(get_G3(), 2)
print("cycle of G3 starting at 2:", cycle)
print("cycle is an euler one:", is_euler(G3, cycle))

# Up to spanning trees and searching

# G: graph
# s: start node: s \in G[0]
def breadth_first_search(G, s):
    # add start node to empty agenda
    # agenda will be used as a *queue*
    #
    # remember the parent so that the appropriate edge
    # could be added afterwards
    # Of course, s does not have any parent at all
    agenda = [(s, None)]  
    marked = set()
    T = []  # edges of the tree

    while agenda:
        u = agenda.pop(0)
        if u[0] in marked:
            continue
        marked.add(u[0])
        if u[1] != None:
            T.append(Edge(u[0], u[1]))  # from child to parent
        for v in adjacent_nodes(G, u[0]):
            if v not in marked:
                agenda.append((v, u[0]))

    return (G[0], T)


# alternative implementation that causes a slightly different
# result because of the different saving of the parents...
# def breadth_first_search(G, s):
#     # add start node to empty agenda; will be used as queue
#     agenda = [s]
    
#     # and remember the parent so that the appropriate edge
#     # could be added afterwards
#     p = {}
#     marked = set()
#     T = []  # edges of the tree

#     while agenda:
#         u = agenda.pop(0)
#         if u in marked:
#             continue
#         marked.add(u)
#         if u in p:
#             T.append(Edge(u, p[u]))  # from child to parent
#         for v in adjacent_nodes(G, u):
#             if v not in marked:
#                 agenda.append(v)
#                 p[v] = u
#         print(agenda)

#     return (G[0], T)


def get_G4():
    V = {1, 2, 3, 4, 5, 6, 7, 8}
    #    a  b  c  d  e  f  g  h
    E = {Edge(1, 2), Edge(1, 5), Edge(1, 4), Edge(2, 6), Edge(2, 3), Edge(3, 7), Edge(3, 4), Edge(4, 8),
         Edge(5, 8), Edge(5, 6), Edge(6, 7), Edge(7, 8)}
    return (V, E)


G4 = get_G4()
G_bread_first = breadth_first_search(G4, 1)
build_dot_graph(G_bread_first, "G_bread_first", 'true')
print("breadth_first_search:", G_bread_first)

# G: graph
# s: start node: s \in G[0]
def depth_first_search(G, s):
    # add start node to empty agenda
    # agenda will be used as a *stack*
    #
    # remember the parent so that the appropriate edge
    # could be added afterwards
    # Of course, s does not have any parent at all
    agenda = [(s, None)]  
    marked = set()
    T = []  # edges of the tree

    while agenda:
        print(agenda)
        u = agenda.pop()
        if u[0] in marked:
            continue
        marked.add(u[0])
        if u[1] != None:
            T.append(Edge(u[0], u[1]))  # from child to parent
        for v in adjacent_nodes(G, u[0]):
            if v not in marked:
                agenda.append((v, u[0]))

    return (G[0], T)


G_depth_first = depth_first_search(G4, 1)
build_dot_graph(G_depth_first, "G_depth_first", 'true')
print("depth_first_search:", G_depth_first)


# Now, it's time to approach the dijkstra algorithm...

# redefinition of E so that it includes costs
Edge = collections.namedtuple("Edge", "u v c")

def get_G1():
    V = {1, 2, 3, 4, 5, 6}
    E = {Edge(1, 2, 3), Edge(2, 3, 7), Edge(3, 6, 1), Edge(3, 5, 5), Edge(4, 1, 5), Edge(5, 6, 10), Edge(5, 1, 4)}
    return (V, E)

G1 = get_G1()

def w(G, s, n):
    for e in G[1]:
        if e.u == s and e.v == n or e.u == n and e.v == s:
            return e.c
    return float("infinity")


print("Kosten von 1 nach 2 in G1:", w(G1, 1, 2))
print("Kosten von 1 nach 3 in G1:", w(G1, 1, 3))


# graph: G
# costs for each edge: w
# start node: s
def dijkstra(G, w, s):
    V = G[0]  # vertices
    R = {s}  # set of result nodes
    p = {}  # mapping of predecessors
    N = V - {s}  # nodes without start node
    c = {}  # mapping: costs for node
    for n in N:  # iterate over all but the start node
        c[n] = w(G, s, n)  # initialize costs for each node of N
        p[n] = None   # no predecessor of node n up to now
    B = adjacent_nodes(G, s)  # initialize the border 
    for b in B:  # set the predecessor of each element of the border
        p[b] = s
    while B:
        # choose f of B so that it is the minimum
        cmin = float("infinity")
        f = None
        for n in B:
            if c[n] < cmin:
                cmin = c[n]
                f = n
        
        B = B - {f}  # remove it from the border
        R = R | {f}  # and add it to the result
        for n in adjacent_nodes(G, f):
            if n not in R:
                B = B | {n}  # add it to the result
                if c[f] + w(G, f, n) < c[n]: # if the total costs are smaller
                    c[n] = c[f] + w(G, f, n)
                    p[n] = f
    return p, c

print(dijkstra(G1, w, 1))
