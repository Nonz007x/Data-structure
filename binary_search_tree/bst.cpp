#include <iostream>

class tree
{
private:
	struct Node {
		int data;
		Node *left;
		Node *right;
		Node(const int &d) : data(d), left(NULL), right(NULL) {}
	};

public:
	Node *root;
	int h = 0, t_h = -1;

	tree() : root(nullptr) {}
	
	void insert(const int data) {
		Node *newNode = new Node(data);

		if (root == NULL) {
			root = newNode;
			return;
		}

		Node *current = root;
		while (true) {
			if (data < current->data) {
				if (current->left == NULL) {
					current->left = newNode;
					return;
				}
				current = current->left;
			}
			else if (data > current->data) {
				if (current->right == NULL) {
					current->right = newNode;
					return;
				}
				current = current->right;
			}
			else {
				delete newNode;
				return;
			}
		}
	}

	void delete1(const int &data) {
		if (root == NULL) {
			return;
		}

		Node *parent = NULL;
		Node *current = root;

		while (current != NULL && current->data != data) {
			parent = current;
			if (data < current->data) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}

		// not found
		if (current == NULL) {
			return;
		}

		// 2 children
		if (current->left != NULL && current->right != NULL) {
			Node *successor = current->right;
			Node *successorParent = current;

			while (successor->left != NULL) {
				successorParent = successor;
				successor = successor->left;
			}

			current->data = successor->data;

			current = successor;
			parent = successorParent;
		}

		Node *child;
		if (current->left != NULL) {
			child = current->left;
		}
		else if (current->right != NULL) {
			child = current->right;
		}
		else {
			child = NULL;
		}

		if (parent == NULL) {
			root = child;
		}
		else if (parent->left == current) {
			parent->left = child;
		}
		else {
			parent->right = child;
		}

		delete current;
	}

	void preorder(Node *current) const {
		if (current != NULL) {

			std::cout << current->data << ",";
			preorder(current->left);
			preorder(current->right);
		}
	}

	void inorder(Node *current) const {
		if (current != NULL) {
			inorder(current->left);
			std::cout << current->data << ",";
			inorder(current->right);
		}
	}

	void postorder(Node *current) const {
		if (current != NULL) {
			postorder(current->left);
			postorder(current->right);
			std::cout << current->data << ",";
		}
	}

	void h_height(Node *n) {
		if (n != NULL) {
			t_h++;
			h_height(n->left);
			h_height(n->right);
			if (t_h > h) {
				h = t_h;
			}
			t_h--;
		}
	}

	int height(int v) {
		Node *n = root;
		while (true) {
			if (n->data > v && n->left != NULL) {
				n = n->left;
			}
			else if (n->data < v && n->right != NULL) {
				n = n->right;
			}

			else if (n->data == v) {
				h = 0, t_h = -1;
				h_height(n);
				return h;
			}

			else {
				return -1;
			}
		}
	}

	void print_level(Node *n, int level) {
		if (level == 0) {
			std::cout << n->data << ",";
		}
		else {
			if (n->left != NULL) {
				print_level(n->left, level - 1);
			}
			if (n->right != NULL) {
				print_level(n->right, level - 1);
			}
		}
	}

	void breadth_first() {
		for (int i = 0; i <= height(root->data); i++) {
			print_level(root, i);
			std::cout << "|";
		}
		std::cout << std::endl;
	}
};

int main(int argc, char **argv) {
	tree plant;
	char choice;
	while (true) {
		std::cin >> choice;

		if (choice == 'x') {
			break;
		}
		if (choice == 'a') {
			int value;
			std::cin >> value;
			plant.insert(value);
		}

		else if (choice == 'd') {
			int value;
			std::cin >> value;
			plant.delete1(value);
		}

		else if (choice == 'i') {
			plant.inorder(plant.root);
			std::cout << "\n";
		}

		else if (choice == 'p') {
			plant.preorder(plant.root);
			std::cout << "\n";
		}

		else if (choice == 't') {
			plant.postorder(plant.root);
			std::cout << "\n";
		}

		else if (choice == 'b') {
			plant.breadth_first();
			std::cout << "\n";
		}
	}

	return 0;
}
