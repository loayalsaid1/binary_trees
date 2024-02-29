class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


a, b, c, d, e, f = Node(3), Node(11), Node(4), Node(4), Node(2), Node(1)

a.left = b
a.right = c
b.left = d
b.right = e
c.right = f

def tree_sum_breadth_first(root):
    """Get the sum of the tree using the itereative way of the
    breadth first algorithm"""
    if root == None:
        return 0
    
    result = 0
    queue = [root]
    
    while (len(queue) > 0):
        curr = queue.pop(0)
        result += curr.val

        if curr.left: queue.append(curr.left)
        if curr.right: queue.append(curr.right)
        
    return result


print(tree_sum_breadth_first(a))
