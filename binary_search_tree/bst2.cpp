#include <iostream>

class Bst {
private:
  struct Node {
    int data;
    Node* left;
    Node* right;
    Node(const int& d): data(d), left(nullptr), right(nullptr){}
  };

public:
  Node* root;

  Bst(): root(nullptr){}

  void insert(const int& value) {
    Node* newNode = new Node(value);
    if (!root) {
      root = newNode;
      return;
    }

    Node* current = root;
    while (true) {
			if (value < current->data) {
				if (current->left == nullptr) {
					current->left = newNode;
					return;
				}
				current = current->left;
			}
			else if (value > current->data) {
				if (current->right == nullptr) {
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

  void remove(const int& value) {
    if (!root) {
      return;
    }

    Node *parent = nullptr;
		Node *current = root;

    while (current != nullptr && current->data != value) {
			parent = current;
			if (value < current->data) {
				current = current->left;
			}
			else if (value > current->data){
				current = current->right;
			}
      else {
        break;
      }
		}

    if (current == nullptr) {
      return;
    }

    if (current->left != NULL && current->right != NULL) {
      parent = current->right;
      Node* successor = parent->left;

      while(successor->left != nullptr) {
        parent = successor;
        successor = successor->left;
      }

			current = successor;
    }
    std::cout << current->data << "\n";

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

  void postorder(Node* current) const {
    if(current != nullptr) {

      postorder(current->left);
      postorder(current->right);
      std::cout << current->data << ",";
    }
  }
};

int main () {
  Bst tree;
  tree.insert(3);
  tree.insert(1);
  tree.insert(2);
  tree.insert(9);
  tree.insert(4);
  tree.insert(10);
  tree.insert(0);
  tree.preorder(tree.root);
}