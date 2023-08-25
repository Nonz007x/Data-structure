#include <iostream>
class Stack {
private:
    int* arr;
    int ptr;

public:
    Stack(size_t size) : ptr(-1) {
        arr = new int[size];
    } 

    ~Stack() {
        delete[] arr;
    }
    void push(const int& value) {
        ptr++;
        arr[ptr] = value;
    }

    void pop() {
        if (!empty())
            ptr--;
    }

    int top() const {
        return arr[ptr];
    }

    bool empty() const {
        if (ptr > -1)
            return true;
        return false;
    }

    size_t size() const {
        return ptr+1;
    }
};

int main() {

    return 0;
}