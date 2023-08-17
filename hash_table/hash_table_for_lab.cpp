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
        int count;
        struct Node {
            int key;
            string value;
            Node* next;
            Node(int k, const string& v) : key(k), value(v), next(nullptr) {}
        };
    std::vector<Node*> table;

    public:
        HashTable() : table(tableSize, nullptr), count(0) {}

    int hashFunction(const int& key) const {
        return key % tableSize;
    }

    void insert(const int& key, const string& value) {
        count++;
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

    string get(const int& key) const {
        const int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return "-";
    }

    void getAll() const {
        Node* current = table[0];
        int i = 0;
        while (i < tableSize) {
            i++;
            if(current != nullptr) {
                while (current != nullptr) {
                    cout << '(' << current->key << ',' << current->value << ')' << ' ';
                    current = current->next; 
                }
                cout << "\n";
            }
            else
                cout << "(-1,-)" << "\n";
            current = table[i];
        }
    }
    
};

int main() {
    HashTable table;
    char input;

	while (true)
	{
        std::cin >> input;
		input = std::tolower(input);
		std::cin.clear();

        if(input == 'e') {
            break;
        }

        if(input == 'a') {
            int key;
            string value;
            std::cin >> key;
            std::cin >> value;
            table.insert(key,value);
        }

        else if (input == 's') {
            int key;
            std::cin >> key;
            cout << table.get(key) << "\n";
        }

        else if (input == 'p') {
            table.getAll();
        }
    }


    return 0;
}