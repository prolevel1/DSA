#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
void deletionEnd(node* &head, int pos) {
	int cnt = 1;

	node* curr = head;
	if (pos == 1) {
		deleteBeg(head);
		return;
	}
	while (cnt != pos - 1) {
		curr = curr->next;
		cnt++;
	}
	node* temp = curr->next;
	curr->next = curr->next->next;
}
void deleteBeg(node* &head) {
	node* curr = head;
	while (curr->next != head) {
		curr = curr->next;
	}
	

}
void insertAtTail(node* &head, int x) {
	node* newnode = new node(x);
	node* curr = head;
	while (curr->next != head) {
		curr = curr->next;
	}
	curr->next = newnode;
	newnode->next = head;

}
void insertAtBeg(node* &head, int x) {
	node* newnode = new node(x);
	node* curr = head;
	if (head == NULL) {
		newnode->next = newnode;
		head = newnode;
		return;
	}
	while (curr->next != head) {
		curr = curr->next;
	}
	curr->next = newnode;
	newnode->next = head;
	head = newnode;

}
void display(node* &head) {
	node* curr = head;
	do {
		cout << curr->data << " ";
		curr = curr->next;
	}while (curr != head);
	cout << endl;
}
int main() {
	node* head = NULL;
	insertAtBeg(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	display(head);
	return 0;
}