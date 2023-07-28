#include <iostream>
#include <memory>
#include <limits>


template <typename T>
class Queue {
private:
    int queue_size;
    int iback;
    int ifront;
    int array_capacity;
    T* array;

public:
    Queue(int capacity) : queue_size(0), iback(-1), ifront(0), array_capacity(capacity) {
        array = new T[capacity];
    }

    ~Queue() {
        delete[] array;
    }

    bool empty() const {
        return queue_size == 0;
    }

    T top() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return array[ifront];
    }

    T bottom() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return array[iback];
    }

    void push(const T& item) {
        if (queue_size >= array_capacity) {
            throw std::out_of_range("Queue is full");
        }
        iback = (iback + 1) % array_capacity;
        array[iback] = item;
        queue_size++;
    }

    T pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        T frontItem = array[ifront];
        ifront = (ifront + 1) % array_capacity;
        queue_size--;
        return frontItem;
    }

    int size() {
        return queue_size;
    }

    void showAll() {
        for (size_t i = ifront; i <= queue_size; i++)
            std::cout << array[i] << ' ';
        std::cout << std::endl;
    }
};

struct Node {
    int data;
    Node* next;
};

int main() {
    std::shared_ptr<Queue<int>> myQueue = std::make_shared<Queue<int>>(100);
    char input;



    while(true) {
        std::cin >> input;
        input = std::tolower(input);
        std::cin.clear();

        if (input == 'x') {
            break;
        }

        if (input == 'e') {
            int number;
            std::cin >> number;
            std::cin.clear();
            
            myQueue->push(number);
        }

        else if (input == 'd') {
            if (!myQueue->empty()) {
                std::cout << myQueue->top() << std::endl;
                myQueue->pop();
            }
        } 

        else if (input == 's') {
            if (!myQueue->empty()) {
                std::cout << myQueue->top() << ' ' << myQueue->bottom() << std::endl;
            }
        } 

        else if (input == 'p') {
            myQueue->showAll();
        } 
        
        else if (input == 'n') {
            std::cout << myQueue->size() << std::endl;
        } 
    }

    return 0;
}
