#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) {
		val = x;
		next = NULL;
	}
};
ListNode* insert(ListNode* &head, int value) {
	ListNode* newnode = new ListNode(value);
	newnode->next = head;
	head = newnode;
	
	return head;
}
void print(ListNode* &head) {
	ListNode* curr = head;
	while (curr != NULL) {
    cout << curr -> val << "-->";
    curr = curr->next;
}
  cout << "null" << endl;
}

void deleteNode(ListNode* &node) {
	node->val = node->next->val;
	node->next = node->next->next;
}
ListNode* startingLL(ListNode* &head) {
	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* temp = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			while (slow                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    != temp) {
				slow = slow->next;
				temp = temp->next;
			}
			return slow;
		}
	}
	return NULL;
}
int main() {
	ListNode* head = NULL;
	head = insert(head, 10);
	head = insert(head, 20);
	head = insert(head, 30);
	head = insert(head, 40);
	print(head);
	ListNode* temp = head->next;
	deleteNode(temp);
	print(head);
	return 0;
}