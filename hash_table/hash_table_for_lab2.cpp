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

    int hashFunction2(const int& key) const {
        Node* current = table[0];
        int index = hashFunction(key);
        int i = 0;
            // cout << index << "\n";
        while(table[index] != nullptr) {
            int f = 11 - (key%11);
            if (table[index]->key == key){
                break;
            }
            i++;
            index = (key + i*f) % tableSize;
            // printf("(%d + %d*%d) %d\n", key, i, f, tableSize);
            // cout << index << "\n";
    
        }
        return index;
    }

    void insert(const int& key, const string& value) {
        int index = hashFunction2(key);
        Node* newNode = new Node(key, value);
        table[index] = newNode;
        count++;

    }

    string get(const int& key) const {
        const int index = hashFunction2(key);
        Node* current = table[index];
        if (current != nullptr) {
            if (current->key == key) {
                    return current->value;
            }
        }
        return "-";
    }

    void getAll() const {
        Node* current = table[0];
        int i = 0;
        while (i < tableSize) {
            i++;
            if(current != nullptr) {
                cout << '(' << current->key << ',' << current->value << ')' << '\n';
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