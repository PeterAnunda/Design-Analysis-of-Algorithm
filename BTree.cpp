#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BTreeNode {
public:
    vector<pair<string, string>> keys;  // (file_name, location)
    vector<BTreeNode*> children;
    bool isLeaf;
    int t;  // Minimum degree

    BTreeNode(int _t, bool _isLeaf) : t(_t), isLeaf(_isLeaf) {}

    void insertNonFull(const string& key, const string& location);
    BTreeNode* search(const string& key);

    // Additional functions for splitting children and inserting in the tree would be added
};

class BTree {
public:
    BTreeNode* root;
    int t;  // Minimum degree

    BTree(int _t) : t(_t) {
        root = new BTreeNode(_t, true);
    }

    void insert(const string& key, const string& location);
    BTreeNode* search(const string& key) {
        return (root == nullptr) ? nullptr : root->search(key);
    }
};

// Implementations of insertion and search functions to be added
