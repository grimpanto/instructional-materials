
class Node:
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None
    def __str__(self):
        return str(self.key) + ", (" + \
            str(self.left) + "), (" + \
            str(self.right) + ")"

def insert(p, key):
    if p == None:
        return Node(key);
    else:
        if key < p.key:
            p.left = insert(p.left, key)
        elif key > p.key:
            p.right = insert(p.right, key)
        return p

def parentSymmSucc(p):
    if p.right.left != None:
        p = p.right
        while p.left.left != None:
            p = p.left
    return p

def remove(p, key):
    if p == None:
        return None
    else:
        if key < p.key:
            p.left = remove(p.left, key)
        elif key > p.key:
            p.right = remove(p.right, key)
        else:
            if p.left == None:
                p = p.right
            elif p.right == None:
                p = p.left
            else:
                q = parentSymmSucc(p)
                if p == q:
                    p.key = q.right.key
                    q.right = q.right.right
                else:
                    p.key = q.left.key
                    q.left = q.left.right
        return p

if __name__ == "__main__":
    root = None
    root = insert(root, 3)
    root = insert(root, 2)
    root = insert(root, 7)
    root = insert(root, 8)
    root = insert(root, 5)
    root = insert(root, 4)
    root = insert(root, 6)
    print(root)
    root = remove(root, 3)
    print(root)
