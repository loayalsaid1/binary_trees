class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


a, b, c, d, e, f = Node(3), Node(11), Node(3), Node(4), Node(15), Node(12)

a.left = b
a.right = c
b.left = d
b.right = e
c.right = f


# def tree_min_deapth_first(root):
#     """Get the minimum value of a binary tree using the depth first approach
#     wiht a stack"""
#     if root is None: return float('inf')
#     minimum = float('inf')
#     stack = [root]

#     while (len(stack) > 0):
#         curr = stack.pop()
#         if curr.val < minimum: minimum = curr.val

#         if curr.right: stack.append(curr.right)
#         if curr.left: stack.append(curr.left)
    
#     return minimum

# print(tree_min_deapth_first(a))



def tree_min_recursive(root):
    """Search for  hte minimum value in the tree recursively"""
    if root is None: return float('inf')

    left_min = tree_min_recursive(root.left)
    right_min = tree_min_recursive(root.right)

    return min([root.val, left_min, right_min])


print(tree_min_recursive(a))
    
