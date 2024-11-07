#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct FibNode {
    int key;
    FibNode* parent;
    FibNode* child;
    FibNode* left;
    FibNode* right;
    bool mark;
    int degree;

    FibNode(int k) : key(k), parent(nullptr), child(nullptr), left(this), right(this), mark(false), degree(0) {}
};

class FibHeap {
public:
    FibNode* minNode;
    int numNodes;

    FibHeap() : minNode(nullptr), numNodes(0) {}

    void insert(int key);
    FibNode* extractMin();
    void decreaseKey(FibNode* node, int newKey);
    // Additional helper methods for linking nodes and consolidating trees would be added
};

// Implementations of insert, extractMin, and decreaseKey to be added
