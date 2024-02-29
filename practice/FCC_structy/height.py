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
        return
    depth_first_print(root.left)
    depth_first_print(root.right)
    print(root.val)


print(depth_first_print(a))



def height(root):
    """get the height or a tree"""
    if root is None or (root.left is None and root.right is None):
        return 0
    
    left_height = height(root.left)
    right_height = height(root.right)

    if left_height >= right_height:
        return left_height + 1
    else:
        return right_height + 1

print(height(d))
