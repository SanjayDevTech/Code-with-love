#def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def searchBST(self, root, val):
        if not root:
            return None
        currentnode = root
        while currentnode:
            if(val<currentnode.val):
                currentnode = currentnode.left
            elif(val > currentnode.val):
                currentnode = currentnode.right
            elif(val == currentnode.val):
                return currentnode
        return None
'''
For example:
        5
        / \
        4   9
        / \
        2   3

    Value to be searched is 4
    Result:-
         4     
        / \   
        2  3
'''