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


def depth_first_print(root):
    """Print a binary tree using hte depth first algorithm;
    implementing it with the stack model via arrays"""
    # check if root is null
    if root is None:
        return []

    result = []
    stack = [root]
    while (len(stack) > 0):
        current = stack.pop()
        result.append(current.val)

        if current.right: stack.append(current.right)
        if current.left: stack.append(current.left)
    return result


print(depth_first_print(a))
