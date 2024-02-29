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


def include_breadth_first(root, value):
    """Check if an element exist in a binary tree or not
    using the breadth first iterative approach"""
    if root is None:
        return False
    
    queue = [root]
    while (len(queue) > 0):
        curr = queue.pop(0)
        if curr.val == value:
            return True
    
        if curr.left: queue.append(curr.left)
        if curr.right: queue.append(curr.right)
    
    return False


print(include_breadth_first(a, 'f'))
