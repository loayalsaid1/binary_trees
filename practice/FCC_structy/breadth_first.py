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


def breadth_first(root):
    """create a breadth first print to a binary tree"""
    if root is None:
        return []
    result = []
    queue = [root]

    while (len(queue) > 0):
        curr = queue.pop(0)
        result.append(curr.val)

        if curr.left: queue.append(curr.left)
        if curr.right: queue.append(curr.right)
    
    return result


print(breadth_first(a))
