class FibHeapNode:
    def __init__(self, key):
        self.key = key
        self.degree = 0
        self.mark = False
        self.parent = None
        self.child = None
        self.prev = self
        self.next = self

class FibHeap:
    def __init__(self):
        self.min_node = None
        self.num_nodes = 0

    def insert(self, key):
        node = FibHeapNode(key)
        if not self.min_node:
            self.min_node = node
        else:
            # Insert into the root list
            self._merge_into_root_list(node)
            if key < self.min_node.key:
                self.min_node = node
        self.num_nodes += 1
        return node

    def extract_min(self):
        # Implement logic to remove and return the minimum node
        pass

    def decrease_key(self, node, new_key):
        if new_key > node.key:
            raise ValueError("New key is greater than current key")
        node.key = new_key
        # Implement decrease key logic, including cut and cascading cut if necessary
        pass

    def _merge_into_root_list(self, node):
        # Merge logic to maintain the doubly linked root list
        pass

# Example usage:
fib_heap = FibHeap()
fib_heap.insert(5)
fib_heap.insert(2)
fib_heap.insert(8)
print(fib_heap.extract_min())  # Should print the node with key 2
