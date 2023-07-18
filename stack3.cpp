#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

void displayStack(const std::stack<int>& st) {
    std::stack<int> tempStack = st;
    std::stack<int> tempStack2;

    while (!tempStack.empty()) {
        int element = tempStack.top();
        tempStack2.push(element);
        tempStack.pop();
    }

    while (!tempStack2.empty()) {
        int element = tempStack2.top();
        tempStack2.pop();
        std::cout << element << " ";
    }

    std::cout << std::endl;
}

int main() {
    stack<int> numberStack;
    string input;

    while (true) {
        std::cout << "Enter : ";
        getline(cin, input);

        if (input == "X" || input == "x") {
            break;
        }


        if (input.length() >= 3 && (input.substr(0, 2) == "U " || (input.substr(0, 2) == "u "))) {
            int number = stoi(input.substr(2));
            numberStack.push(number);
        }

        else if (input == "T" || input == "t") {
            if (!numberStack.empty())
                std::cout << numberStack.top() << std::endl;
        }

        else if (input == "O" || input == "o") {
            if (!numberStack.empty()) {
                numberStack.pop();
                if(!numberStack.empty()) {
                    std::cout << numberStack.top() << std::endl;
                }
            }
        } 

        else if (input == "P" || input == "p") {
            displayStack(numberStack);
        } 
        
        else if (input == "N") {
            std::cout << numberStack.size() << std::endl;
        }
    }

    return 0;
}


