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


def find_lca(root, n1, n2):
    if root is None:
        return None

    if root == n1 or root == n2:
        return root
    

    left = find_lca(root.left, n1, n2)
    right = find_lca(root.right, n1, n2)

    if left and right:
        return root
    
    if left:
        return left
    else:
        return right

print(find_lca(a,d, d).val)
