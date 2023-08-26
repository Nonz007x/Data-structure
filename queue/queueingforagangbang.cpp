#include <iostream>

using std::cout;
using std::endl;

class Queue {
private:
    int* array;
    int front;
    int back;
    const int MAX_SIZE;
    int size;

public:
    Queue(const int& MAX_SIZE) : MAX_SIZE(MAX_SIZE), size(0), front(0), back(-1) {
        array = new int[MAX_SIZE];
    }

    ~Queue() {
        delete[] array;
    }


    bool empty() const {
        return size <= 0;
    }

    int pop() {
        if (!empty()) {
            int result = array[front];
            front = (front + 1) % MAX_SIZE;
            size--; 
            return result;
        } else
        cout << "Queue is empty!\n";
        return -1;
    }

    void push(const int& value) {
        if (size < MAX_SIZE) {
            back = (back + 1) % MAX_SIZE;
            array[back] = value;
            size++;
        } else
        cout << "Queue is full!\n";
    }

    int getFront() const {
        return array[front];
    }

    int getBack() const {
        return array[back];
    }

    void print() const {
        int current = front;    
        do {
            cout << array[current] << " ";
            current = (current + 1) % MAX_SIZE;
        } while (current != (back + 1) % MAX_SIZE);
        cout << endl;
    }

    void printReverse() const {
        int current = front;    
        do {
            cout << array[current] << " ";
            current = (current + 1) % MAX_SIZE;
        } while (current != (back + 1) % MAX_SIZE);
        cout << endl;
    }
};

int main() {
    Queue q1(4);
    q1.push(3);
    q1.push(31);
    q1.push(323);
    q1.push(343);
    q1.pop();
    q1.push(666);
    q1.print();

}