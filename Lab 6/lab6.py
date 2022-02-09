
# Lab 6

#
# We'll define a node of a binary tree and introduce some features of Python
# classes along the way


class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        '''
        node.insert(5) is the same as BST.insert(node, 5)
        We use this when recursively calling, e.g. self.left.insert
        '''
        if value < self.value:
            if self.left == None:
                self.left = BST(value)
            else:
                self.left.insert(value)
        else:
            if self.right == None:
                self.right = BST(value)
            else:
                self.right.insert(value)

    def __repr__(self):
        '''The string representation of a node.
        Here, we convert the value of the node to a string and make that
        the representation.
        We can now use
        a = Node(4)
        print(a) # prints 4
        '''
        return str(self.value)



a = BST(4)
a.insert(2)
a.insert(5)
a.insert(10)
a.insert(3)
a.insert(15)
# a.insert(4)

# Problem 1
# Draw (manually) the binary tree rooted in a.
'''
      4
     / \
    2   5
   / \ / \
     3   10
        / \
          15
'''
# Problem 2
# Write code to find the height of a Binary Search Tree
def DFS_height(node):
    if node == None or (node.left == None and node.right == None):
        return 0
    return max(DFS_height(node.left), DFS_height(node.right)) + 1


# Problem 3

# Write code to print out the nodes of the BST using
# Breadth-First Search. How would you get the Breadth-First Traversal
# from the tree you've drawn?
# (Modify the BFS function from lecture for this problem)

def BFS_tree(node):
    DS = [node]
    l = []
    while(len(DS)>0):
        cur = DS.pop(0)
        l.append(cur.value)
        if cur.left != None:
            DS.append(cur.left)
        if cur.right != None:
            DS.append(cur.right)
    return l


# Problem 4

# Empirically investigate the relationship between the number of nodes in the
# tree and the height of the tree when inserting nodes with values generated
# using random.random()

import random

def make_random_tree(n_nodes):
    '''Make a tree with n_nodes nodes by inserting nodes with values
    drawn using random.random()
    '''
    a = BST(random.random())
    for i in range(n_nodes-1):
        a.insert(random.random())
    return a

def height_random_tree(n_nodes):
    '''Generate a random tree with n_nodes nodes, and return its height'''
    return DFS_height(make_random_tree(n_nodes))

def make_data(max_nodes):
    '''Make two lists representing the empirical relationship between
    the number of nodes in a random tree and the height of the tree.
    Generate N_TREES = 40 trees with each of
    n_nodes = 5, int(1.2*5), int(1.2^2*5), .....

    return n (a list of values of n_nodes) and h (a list of heights)

    '''
    N_TREES = 40
    n_nodes = 5
    n = []
    h = []

    for i in range(N_TREES):
        n.append(int((1.2**i)*n_nodes))
        h.append(height_random_tree(n[i]))

    return n, h

# n, h = make_data(10000)
# import matplotlib.pyplot as plt
# plt.scatter(n, h)
# plt.show()

# plt.savefig("trees.png") can save the data to disk












