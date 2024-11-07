class Node:
    def __init__(self, isbn, book_data):
        self.isbn = isbn
        self.book_data = book_data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, isbn, book_data):
        """Insert a new book record by ISBN."""
        if not self.root:
            self.root = Node(isbn, book_data)
        else:
            self._insert_recursive(self.root, isbn, book_data)

    def _insert_recursive(self, current_node, isbn, book_data):
        if isbn < current_node.isbn:
            if current_node.left is None:
                current_node.left = Node(isbn, book_data)
            else:
                self._insert_recursive(current_node.left, isbn, book_data)
        elif isbn > current_node.isbn:
            if current_node.right is None:
                current_node.right = Node(isbn, book_data)
            else:
                self._insert_recursive(current_node.right, isbn, book_data)
        else:
            print("Duplicate ISBNs are not allowed.")

    def search(self, isbn):
        """Search for a book by ISBN and return its data."""
        return self._search_recursive(self.root, isbn)

    def _search_recursive(self, current_node, isbn):
        if current_node is None:
            return None
        if isbn == current_node.isbn:
            return current_node.book_data
        elif isbn < current_node.isbn:
            return self._search_recursive(current_node.left, isbn)
        else:
            return self._search_recursive(current_node.right, isbn)

    def delete(self, isbn):
        """Delete a book record by ISBN."""
        self.root = self._delete_recursive(self.root, isbn)

    def _delete_recursive(self, current_node, isbn):
        if current_node is None:
            return None

        if isbn < current_node.isbn:
            current_node.left = self._delete_recursive(current_node.left, isbn)
        elif isbn > current_node.isbn:
            current_node.right = self._delete_recursive(current_node.right, isbn)
        else:
            # Node with only one child or no child
            if current_node.left is None:
                return current_node.right
            elif current_node.right is None:
                return current_node.left

            # Node with two children: get the inorder successor
            min_larger_node = self._get_min(current_node.right)
            current_node.isbn, current_node.book_data = min_larger_node.isbn, min_larger_node.book_data
            current_node.right = self._delete_recursive(current_node.right, min_larger_node.isbn)

        return current_node

    def _get_min(self, node):
        while node.left is not None:
            node = node.left
        return node

# Example usage
bst = BST()
bst.insert(12345, {"title": "Book A", "author": "Author A"})
bst.insert(67890, {"title": "Book B", "author": "Author B"})
print(bst.search(12345))  # Should print details of "Book A"
bst.delete(12345)
print(bst.search(12345))  # Should print None
