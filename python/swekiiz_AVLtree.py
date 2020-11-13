class Node:
    def __init__(self, data=None):
        self.data = data
        self.right = self.left = None
        self.height = 1
    def getHigh(self, cur):
        return 0 if cur == None else cur.height
    def insert(self, data, cur=-1):
        check = False
        if cur == -1:
            cur = self
        if self.data == None:
            self.data = data
            return self, check
        if cur is None:
            return Node(data), check
        if data < cur.data:
            cur.left, check = self.insert(data, cur.left)
        elif data > cur.data:
            cur.right, check = self.insert(data, cur.right)
        cur.height = 1 + max(self.getHigh(cur.right), self.getHigh(cur.left))
        b = self.getHigh(cur.left) - self.getHigh(cur.right)
        if b > 1 and data < cur.left.data:
            check = True
            return self.rightRotate(cur), check
        if b < -1 and data > cur.right.data:
            check = True
            return self.leftRotate(cur), check
        if b > 1 and data > cur.left.data:
            check = True
            cur.left = self.leftRotate(cur.left)
            return self.rightRotate(cur), check
        if b < -1 and data < cur.right.data:
            check = True
            cur.right = self.rightRotate(cur.right)
            return self.leftRotate(cur), check
        return cur, check
    def leftRotate(self, cur):
        m, t = cur.right, cur.right.left
        m.left = cur
        cur.right = t
        cur.height = 1 + max(self.getHigh(cur.right), self.getHigh(cur.left))
        m.height = 1 + max(self.getHigh(m.right), self.getHigh(m.left))
        return m
    def rightRotate(self, cur):
        m, t = cur.left, cur.left.right
        m.right = cur
        cur.left = t
        cur.height = 1 + max(self.getHigh(cur.right), self.getHigh(cur.left))
        m.height = 1 + max(self.getHigh(m.right), self.getHigh(m.left))
        return m
    def printTree90(self, level=0):
        if self.right != None:
            self.right.printTree90(level + 1)
        print('     ' * level, self.data)
        if self.left != None:
            self.left.printTree90(level + 1)
root = Node()
data = list(map(int, input('Enter Input : ').strip().split()))
for e in data:
    print("insert :", e)
    root, check = root.insert(e)
    if check: print('Not Balance, Rebalance!')
    root.printTree90()
    print("===============")
