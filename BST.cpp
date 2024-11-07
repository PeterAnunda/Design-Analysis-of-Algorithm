#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct Node {
    int isbn;
    string bookData;
    Node* left;
    Node* right;

    Node(int isbn, const string& data) : isbn(isbn), bookData(data), left(nullptr), right(nullptr) {}
};

class BookBST {
private:
    Node* root;

    Node* insert(Node* node, int isbn, const string& bookData) {
        if (node == nullptr) {
            return new Node(isbn, bookData);
        }
        if (isbn < node->isbn) {
            node->left = insert(node->left, isbn, bookData);
        } else if (isbn > node->isbn) {
            node->right = insert(node->right, isbn, bookData);
        } else {
            cout << "Duplicate ISBNs are not allowed." << endl;
        }
        return node;
    }

    Node* search(Node* node, int isbn) const {
        if (node == nullptr || node->isbn == isbn) {
            return node;
        }
        if (isbn < node->isbn) {
            return search(node->left, isbn);
        } else {
            return search(node->right, isbn);
        }
    }

    Node* deleteNode(Node* node, int isbn) {
        if (node == nullptr) {
            return nullptr;
        }

        if (isbn < node->isbn) {
            node->left = deleteNode(node->left, isbn);
        } else if (isbn > node->isbn) {
            node->right = deleteNode(node->right, isbn);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: get the inorder successor
            Node* temp = getMin(node->right);
            node->isbn = temp->isbn;
            node->bookData = temp->bookData;
            node->right = deleteNode(node->right, temp->isbn);
        }
        return node;
    }

    Node* getMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    BookBST() : root(nullptr) {}

    void insert(int isbn, const string& bookData) {
        root = insert(root, isbn, bookData);
    }

    string search(int isbn) const {
        Node* result = search(root, isbn);
        if (result != nullptr) {
            return result->bookData;
        } else {
            return "Book not found.";
        }
    }

    void deleteISBN(int isbn) {
        root = deleteNode(root, isbn);
    }
};

// Example usage
int main() {
    BookBST bst;
    bst.insert(12345, "Book A by Author A");
    bst.insert(67890, "Book B by Author B");
    cout << bst.search(12345) << endl;  // Should print details of "Book A"
    bst.deleteISBN(12345);
    cout << bst.search(12345) << endl;  // Should print "Book not found."
    return 0;
}
