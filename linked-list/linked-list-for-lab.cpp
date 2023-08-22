#include <iostream>

class Node
{
public:
	int data;
	Node *next;

	Node(const int &value) : data(value), next(nullptr) {}
};

class List
{
private:
	Node *head;

public:
	List() : head(nullptr) {}

	~List() {
		while (head) {
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}

	int search(const int &pos) {
		Node *ptr = head;
		int i = 0;
		while (ptr)
		{
			if (ptr->data == pos)
				return i;
			ptr = ptr->next;
			i++;
		}
		return -1;
	}

	void append(const int &value) {
		Node *newNode = new Node(value);
		if (!head)
		{
			head = newNode;
		}
		else
		{
			Node *current = head;
			while (current->next)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}

	void appendAt(const int &value, const int &id) {
		Node *newNode = new Node(value);

		if (search(value) != -1)
			return;

		int pos = search(id);

		if (pos == -1){
			append(value);
			return;
		} else if (pos == 0){
			newNode->next = head;
			head = newNode;
			return;
		}

		Node *current = head;
		Node *temp;
		while (pos != 0 && current){
			pos--;
			temp = current;
			current = current->next;
		}

		if (current){
			temp->next = newNode;
			newNode->next = current;
		}
	}

	void appendAfter(const int &value, const int &id) {
		Node *newNode = new Node(value);
		Node *current = head;
		Node *temp;

		int pos = search(id);
		if (pos == -1) {
			append(value);
			return;
		}

		if (search(value) != -1)
			return;

		while (pos != 0 && current) {
			pos--;
			current = current->next;
		}
			newNode->next = current->next;
			current->next = newNode;
	}

	void deleteAt(const int &id) {
		Node *current = head;
		Node *shit = head;
		Node *temp;
		int i = 0;

		int index = search(id);
		if (index == -1)
			return;
		else if (index == 0) {
			Node *current = head;
			current = current->next;
			head = current;
			return;
		}

		while (i < index && current) {
			i++;
			temp = current;
			current = current->next;
		}

		temp->next = current->next;
		delete current;
	}

	void edit(const int &value, const int &id) {	
		Node* current = head;
		int pos = search(id);

		if (pos == -1 || search(value) != -1){
			std::cout << pos << ' ' << search(value) << "\n"; 
			return;
			}

		while(pos != 0 && current) {
			pos--;
			current = current->next;
		}
		current->data = value;
		std::cout << current->data << "\n";
	}

	void print() const {
		Node *current = head;
		while (current)
		{
			std::cout << current->data << ' ';
			current = current->next;
		}
		std::cout << "\n";
	}
};
int main() {
	List myList;
	char input;

	while (true) {
		std::cin >> input;
		input = std::tolower(input);
		std::cin.clear();

		if (input == 'e'){
			break;
		}

		if (input == 'i') {
			int number, number2;
			std::cin >> number;
			std::cin >> number2;

			if (myList.search(number) == -1)
			{
				myList.appendAt(number, number2);
				myList.print();
			}
		}

		else if (input == 'a') {
			int number, number2;
			std::cin >> number;
			std::cin >> number2;
			if (myList.search(number) == -1) {
				myList.appendAfter(number, number2);
				myList.print();
			}
		}

		else if (input == 'd') {
			int number;
			std::cin >> number;
			if (myList.search(number) != -1) {
				myList.deleteAt(number);
				myList.print();
			}
		}

		else if (input == 'r') {
			int number, number2;
			std::cin >> number;
			std::cin >> number2;
			if (myList.search(number) == -1) {
				myList.edit(number, number2);
				myList.print();
			}
		}
	}

	return 0;
}
