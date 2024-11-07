#include <vector>
#include <iostream>

class DisjointSetUnion {
public:
    std::vector<int> parent;
    std::vector<int> rank;

    DisjointSetUnion(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            // Path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Example usage:
int main() {
    DisjointSetUnion dsu(10);
    dsu.unionSets(1, 2);
    dsu.unionSets(2, 3);
    std::cout << (dsu.find(1) == dsu.find(3)) << std::endl;  // Should print 1 (true)
    std::cout << (dsu.find(1) == dsu.find(4)) << std::endl;  // Should print 0 (false)
    return 0;
}
