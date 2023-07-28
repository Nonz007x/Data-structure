#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
    private:
        T arr[100] = {};
        int stackPointer = -1;

    public:
        void push(T element) {
            stackPointer++;
            arr[stackPointer] = element;
        }

        void pop() {
            stackPointer--;
        }

        T top() {
            return arr[stackPointer];
        }

        bool empty() {
            return !(stackPointer + 1);
        }

        void showAll() {
            for (size_t i = 0; i <= stackPointer; i++)
                std::cout << arr[i] << ' ';
            std::cout << endl;
        }

        int size() {
            return stackPointer+1;
        }
};

int main() {
    Stack<int> numberStack;

    while (true) {
        char input;
        std::cin >> input;
        input = std::toupper(input);

        if (input == 'X') {
            break;
        }

        if (input == 'U') {
            int number;
            std::cin >> number;
            numberStack.push(number);
        }

        else if (input == 'T') {
            if (!numberStack.empty())
                std::cout << numberStack.top() << std::endl;
        }

        else if (input == 'O') {
            if (!numberStack.empty()) {
                std::cout << numberStack.top() << std::endl;
                numberStack.pop();
            }
        } 

        else if (input == 'P') {
            numberStack.showAll();
        } 
        
        else if (input == 'N') {
            std::cout << numberStack.size() << std::endl;
        }
    }

    return 0;
}


