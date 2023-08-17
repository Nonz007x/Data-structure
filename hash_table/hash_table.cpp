#include <functional>

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;

class HashTable {
    private:
        static const int tableSize = 17;
        struct Node {
            string key;
            int value;
            Node* next;
            Node(const string& k, int v) : key(k), value(v), next(nullptr) {}
        };
    std::vector<Node*> table;

    public:
        HashTable() : table(tableSize, nullptr) {}

    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % tableSize;
    }

    void insert(const std::string& key, int value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int get(const std::string& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Key not found
    }
    
};

int main() {
    HashTable table;
    table.insert("gasoline",1);
    cout << table.get("gasolie") << "\n";

    return 0;
}