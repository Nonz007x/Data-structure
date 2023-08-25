#include <iostream>

using std::cout;
class LinkList {
private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
        Node(const int& d) : value(d), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    LinkList() : head(nullptr), tail(nullptr) {}

    ~LinkList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertEnd(const int& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertFront(const int& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
                head = newNode;
                tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtIndex(int index, const int& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        if (index <= 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        
        Node* current = head;
        Node* previous;
        while(index > 0 && current != nullptr) {
            index--;
            previous = current; 
            current = current->next;
        }

        if (current != nullptr) {
            current->prev = newNode;
        } else {
            tail = newNode;
        }

        previous->next = newNode;
        newNode->next = current;
        newNode->prev = previous;
    }

    void insertAfterIndex(int index, const int& value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        if (index < 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node* current = head;
        while (index > 0 && current->next != nullptr) {
            current = current->next;
            index--;
        }

        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
            newNode->next = current->next;
            newNode->prev = current;
            current->next = newNode;
    }

    void deleteAtIndex(int index) {
        Node* current = head;
        Node* previous;

        if (index == 0) {
            head = current->next;
            delete current;
            return;
        }

        while (index > 0 && current != nullptr) {
            previous = current;
            current = current->next;
            index--;
        }

        if (current == nullptr){
            return;
        }
            previous->next = current->next;
            tail = previous;
            delete current;
        
    }

    void deleteFront() {
        Node* temp = head;
        head = temp->next;
        delete temp;
        temp = nullptr;
    }

    void deleteEnd() {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        temp = nullptr;
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << std::endl;
    }
};

int main() {
    LinkList list;
    list.insertFront(4);
    list.insertFront(5);
    list.insertFront(6);
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(10);
    list.insertAfterIndex(1,10);

    list.print();

    return 0;
}