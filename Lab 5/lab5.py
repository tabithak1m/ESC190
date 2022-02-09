import numpy as np

class Node:
    def __init__(self, name):
        self.name = name
        self.connections = []
        self.visited = False


def connect(node1, node2, weight):
    node1.connections.append({"node": node2, "weight": weight})
    node2.connections.append({"node": node1, "weight": weight})


def BFS(node):
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        print(cur.name)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"])
                con["node"].visited = True


################################################################################

def get_all_nodes(node):
    '''Return a list of the nodes in the graph of nodes connected to node
    (N.B., the nodes can be indirectly connected as well)'''
    unvisit_all(node)
    list = []
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        list.append(cur)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"])
                con["node"].visited = True
    unvisit_all(node)
    return list



################################################################################

def unvisit_all(node):
    '''Change all n.visited to False in all the nodes in the graph of nodes
    connected to node. Use BFS to find all the nodes'''
    q = [node]
    node.visited = False
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        for con in cur.connections:
            if con["node"].visited:
                q.append(con["node"])
                con["node"].visited = False



###############################################################################

def DFS_rec(node):
    '''Print out the names of all nodes connected to node using a
    recursive version of DFS'''
    print(node.name)
    node.visited = True
    for node2 in node.connections:
        if not node2["node"].visited:
            DFS_rec(node2["node"])



################################################################################

def DFS_nonrec(node):
    '''Print out the names of all nodes connected to node using a non-recursive
    version of DFS. Make it so that the nodes are printed in the same order
    as in DFS_rec'''
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop(-1)
        print(cur.name)
        for con in cur.connections[::-1]:
            if not con["node"].visited:
                q.append(con["node"])
                con["node"].visited = True


################################################################################
#
# OPTIONAL
#
import numpy

def dijsktra_slowish_ans(node):
    S = [node]
    d = {node.name: 0}

    unexplored = get_all_nodes(node)
    unexplored.remove(node)

    # O(|edges| * |v|), if e is unknown, O(|v|^3)
    while len(unexplored) > 0:
        cur_min_dist = np.inf
        cur_to_add = None

        # O(edges)
        for cur in unexplored:
            for con in cur.connections:
                if con["node"] in S:
                    dist = d[con["node"].name] + con["weight"]
                    if dist < cur_min_dist:
                        cur_min_dist = dist
                        cur_prev = con["node"].name
                        cur_to_add = cur
        unexplored.remove(cur_to_add)
        S.append(cur_to_add)
        d[cur_to_add.name] = cur_min_dist
        cur_to_add.prev = cur_prev

    return d



def dijsktra_slowish(node):
    '''Implement Dijkstra's algorithm as discussed in class (i.e., you don't
    need to use a priority queue'''
    S = [node]
    d = {node.name: 0}

    unexplored = get_all_nodes(node)
    unexplored.remove(node)

    while (len(unexplored)) > 0:
        distance = {}
        for v in unexplored:
            if is_neighbour(S, v)[0]:
                distance[v] = d[is_neighbour(S, v)[1]] + is_neighbour(S, v)[2]
        d[find_min(distance)[0].name] = find_min(distance)[1]
        S.append(find_min(distance)[0])
        unexplored.remove(find_min(distance)[0])
    return d

def find_min(dict):
    minimum = min(dict.values())
    for node, distance in dict.items():
        if dict[node] == minimum:
            return [node, minimum]

def is_neighbour(list, v):
    for i in list:
        for con in i.connections:
            if con["node"] == v:
                return [True, i.name, con["weight"]]
    return [False]


################################################################################

def dijsktra(source):
    Q = get_all_nodes(source)
    d = {}
    for node in Q:
        d[node.name] = 999999
    d[source.name] = 0

    while len(Q) > 0:
        v = Q[0]
        for node in Q:
            if d[node.name] < d[v.name]:
                v = node
        Q.remove(v)

        for con in v.connections:
            dist = d[v.name] + con["weight"]
            if dist < d[con["node"].name]:
                d[con["node"].name] = dist
    return d


################################################################################


# def print_l(list):
#     l = []
#     for i in list:
#         l.append(i.name)
#     print(l)
#
# def return_l(list):
#     l = []
#     for i in list:
#         l.append(i.name)
#     return l

# def dijsktra_slowish(node):
#     '''Implement Dijkstra's algorithm as discussed in class (i.e., you don't
#     need to use a priority queue'''
#     S = [node]
#     d = {node.name: 0}
#
#     unexplored = get_all_nodes(node)
#     unexplored.remove(node)
#     print(len(unexplored))
#
#     while len(unexplored) > 0:
#         x = len(S)
#         print("x: ", x)
#         # print("while")
#         for con in S[-1].connections:
#             print("con: ", con["node"].name, " S[-1]: ",S[-1].name)
#             # print("for")
#             if not con["node"].name in d.keys():
#                 d[con["node"].name] = con["weight"] + d[S[-1].name]
#             elif (con["weight"] + d[S[-1].name]) < d[con["node"].name]:
#                 d[con["node"].name] = con["weight"] + d[S[-1].name]
#
#         # for con in S[-1].connections:
#             # print("for 2")
#             if (con["node"]) in unexplored and len(S) == x:
#                 # print("if")
#                 S.append(con["node"])
#                 unexplored.remove(con["node"])
#                 print("len S: ", len(S))
#         print_l(unexplored)
#         print_l(S)
#
#     return d




if __name__ == '__main__':
    TO = Node("TO")
    NYC = Node("NYC")
    DC = Node("DC")
    CDMX = Node("CDMX")
    SF = Node("SF")

    connect(TO, NYC, 3)
    connect(TO, SF, 6)
    connect(TO, CDMX, 7)
    connect(NYC, DC, 2)
    connect(SF, DC, 5)

    L = get_all_nodes(TO)
    # BFS(TO)
    # DFS(TO)
    # DFS_rec(TO)
    unvisit_all(TO)
    # DFS(TO)
    # print(dijsktra_slowish(TO))