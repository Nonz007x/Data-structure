#include <iostream>
#include <bits/stdc++.h>

// void swap(int& a, int& b);

class heap {
	private:
		int* size;
		const int MAX_SIZE = 1000;
	public:
		int q[1000];

		heap() {
			std::fill_n(q, 1000, INT_MIN);
			q[0] = 0;
			size = &q[0];
		}

		void insert(const int& n) { // heapify bottom-up
			if (*size < MAX_SIZE - 1) {
					(*size)++; // increase size;
					q[(*size)] = n;
					int index = *size;
					int parent = index / 2;

					while (index > 1 && q[parent] > q[index]) { // check if parent is less than inserted child 🥵😭
							std::swap(q[index], q[parent]);
							index = parent;
							parent = index / 2;
					}
			}
		}

		int pop() { // heapify top-down
			if(*size > 0) {
				int tempTopNode = q[1];
				q[1] = q[*size];
				(*size)--;

				int parent = 1;
				while(parent <= *size) {
					int left = parent*2;
					int right = (parent*2) + 1;

					if (left <= *size && q[left] < q[parent] && q[left] <= q[right]) {
						std::swap(q[left], q[parent]);
						parent = left;
					}
					else if (right <= *size && q[right] < q[parent] && q[right] <= q[left]) {
						std::swap(q[right], q[parent]);
						parent = right;
					} else {
						break;
					}	
				}
				
				return tempTopNode;
			
			}
			else {
				return -1;
			}
		}

		void print() {
			for(int i = 1; i <= *size; i++) {
				std::cout << q[i] << " ";
			}
			std::cout << std::endl;
		}
};

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
    heap h;

    char choice;
    while (true) {
        std::cin >> choice;

        switch (choice) {
            case 'e':
                return 0;
                break;

            case 'a':
                int n;
                std::cin >> n;
                h.insert(n);
                break;

            case 'p':
                h.print();
                break;

            case 'd':
                std::cout << h.pop() << std::endl;
                break;

            default:
                std::cerr << "Invalid choice: " << choice << std::endl;
                break;
        }
    }
}
