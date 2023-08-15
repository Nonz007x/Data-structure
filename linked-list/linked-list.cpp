#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> myList;
    myList.append(10);
    myList.append(20);
    myList.append(30);
    myList.display();


    return 0;
}
