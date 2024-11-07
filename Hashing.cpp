#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>

using namespace std;

class UserHashTable {
private:
    int size;
    vector<list<pair<string, string>>> table;

    int hashFunction(const string& username) const {
        // Simple hash function using std::hash and modulo operation
        return hash<string>()(username) % size;
    }

public:
    UserHashTable(int tableSize = 10) : size(tableSize) {
        table.resize(size);
    }

    void addUser(const string& username, const string& profileData) {
        int index = hashFunction(username);
        // Check if the username already exists and update if so
        for (auto& pair : table[index]) {
            if (pair.first == username) {
                pair.second = profileData;
                cout << "Updated user " << username << " at index " << index << endl;
                return;
            }
        }
        // Add new user if not found
        table[index].emplace_back(username, profileData);
        cout << "Added user " << username << " at index " << index << endl;
    }

    string getUser(const string& username) const {
        int index = hashFunction(username);
        for (const auto& pair : table[index]) {
            if (pair.first == username) {
                return pair.second;
            }
        }
        cout << "User " << username << " not found." << endl;
        return "";
    }
};

// Example usage
int main() {
    UserHashTable userTable;
    userTable.addUser("alice123", "Alice, 25, NY");
    userTable.addUser("bob456", "Bob, 30, LA");
    cout << userTable.getUser("alice123") << endl; // Should print Alice's profile data
    cout << userTable.getUser("charlie789") << endl; // Should print "User charlie789 not found."
    return 0;
}
