class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


a, b, c, d, e, f = Node('a'), Node('b'), Node('c'), Node('d'), Node('e'), Node('f')

a.left = b
a.right = c
b.left = d
b.right = e
c.right = f


def recursive_include(root, target):
    """Search for the exestence of a target value in a binary tree
    using depth first recursive way"""
    if root is None: return False
    if root.val == target: return True

    return recursive_include(root.left, target) or recursive_include(root.right, target)


print(recursive_include(a, 'f'))
