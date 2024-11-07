class BTreeNode:
    def __init__(self, t, is_leaf=True):
        self.t = t  # Minimum degree (defines the range for the number of keys)
        self.is_leaf = is_leaf
        self.keys = []  # List of keys
        self.children = []  # List of children pointers

class BTree:
    def __init__(self, t):
        self.root = BTreeNode(t)
        self.t = t

    def insert(self, key, location):
        # Insert logic for B-tree (to be implemented based on B-tree properties)
        pass

    def search(self, key, node=None):
        if node is None:
            node = self.root
        i = 0
        while i < len(node.keys) and key > node.keys[i][0]:
            i += 1
        if i < len(node.keys) and key == node.keys[i][0]:
            return node.keys[i][1]  # Return location associated with file_name
        if node.is_leaf:
            return None
        return self.search(key, node.children[i])

# Example usage:
btree = BTree(3)  # Minimum degree of 3
btree.insert("file1.txt", "/path/to/file1")
print(btree.search("file1.txt"))  # Should print "/path/to/file1"
