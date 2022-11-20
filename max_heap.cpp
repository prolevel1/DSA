#include <bits/stdc++.h>
using namespace std;
class Max_heap {
	int *arr;
	int size;
	int cap;
    public:
	Max_heap(int s) {
		arr = new int[s];
		size = 0;
		cap = s;
	}

	int left(int i) {
		return (2 * i + 1);
	}
	int right(int i) {
		return (2 * i + 2);
	}
	int parent(int i) {
		return (i / 2);
	}
	void insert(int val) {
		size = size + 1;
		int index = size;
		arr[index] = val;
		
		while (index > 1) {
			int p = parent(index);
			if (arr[index] > arr[p]) {
				swap (arr[index], arr[p]);
				index = p;
			}
			else {
				return;
			}
		}
	}
	void print() {
		for (int i = 1; i <= size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Max_heap h(5);
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);

	h.print();
	return 0;

}
