class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


a, b, c, d, e, f = Node(5), Node(11), Node(3), Node(4), Node(2), Node(1)

a.left = b
a.right = c
b.left = d
b.right = e
c.right = f



def max_root_leaf_path(root):
    if root is None: return float('-inf')
    if root.left is None and root.right is None: return root.val

    left_max_sum = max_root_leaf_path(root.left)
    right_max_sum = max_root_leaf_path(root.right)

    return max([left_max_sum, right_max_sum]) + root.val



print(max_root_leaf_path(a))
