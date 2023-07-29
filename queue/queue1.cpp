#include <iostream>
#include <memory>
#include <limits>

using std::cout;
using std::endl;

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

    T front() const {
        return array[ifront];
    }

    T back() const {
        return array[iback];
    }

    void push(const T& item) {
        iback = (iback + 1) % array_capacity;
        array[iback] = item;
        queue_size++;
    }

    void pop() {
        ifront = (ifront + 1) % array_capacity;
        queue_size--;
    }

    int size() const {
        return queue_size;
    }

    void showall() const {
        size_t current = ifront;
        do {
            cout << array[current] << ' ';
            current = (current + 1) % array_capacity;
        } while (current != (iback + 1) % array_capacity);

        cout << '\n';
    }
};

int main() {
    std::shared_ptr<Queue<int>> myQueue = std::make_shared<Queue<int>>(5);
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
                cout << myQueue->front() << '\n';
                myQueue->pop();
            }
        } 

        else if (input == 's') {
            if (!myQueue->empty()) {
                cout << myQueue->front() << ' ' << myQueue->back() << '\n';
            }
        } 

        else if (input == 'p') {
            myQueue->showall();
        } 
        
        else if (input == 'n') {
            cout << myQueue->size() << '\n';
        } 
    }

    cout << endl;

    return 0;
}
