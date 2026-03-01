#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};
struct DLinkedList{
	Node* head = nullptr;
	Node* tail = nullptr;
};
void push_front(DLinkedList& l, int val){
	Node* newNode = new Node();
	newNode->data = val;
	if (l.head == NULL){
		l.head = l.tail = newNode;
		return;
	}
	newNode->next = l.head;
	l.head->prev = newNode;
	l.head = newNode;
}

void push_back(DLinkedList& l, int val){
	Node* newNode = new Node();
	newNode->data = val;
	if (l.head == NULL){
		l.head = l.tail = newNode;
		return;
	}
	l.tail->next = newNode;
	newNode->prev = l.tail;
	l.tail = newNode;
}

void pop_front(DLinkedList& l){
	if (l.head == NULL){
		cout << "Linked List is empty.\n";
		return;
	}
	Node* temp = l.head;
	l.head = l.head->next;
	if (l.head != NULL){
		l.head->prev = NULL;
	}
	temp->next = NULL;
	delete temp;
}

void pop_back(DLinkedList& l){
	if (l.head == NULL){
		cout << "Linked List is empty.\n";
		return;
	}
	Node* temp = l.tail;
	l.tail = l.tail->prev;
	if (l.tail != NULL)
		l.tail->next = NULL;
	temp->prev = NULL;
	delete temp;
}

void insertt(DLinkedList& l, int val, int pos){
	if (pos < 0){
		cout << "Invalid Position.\n";
		return;
	}
	if (l.head == NULL){
		push_back(l, val);
		return;
	}
	if (pos == 0){
		push_front(l ,val);
	}
	Node* newNode = new Node();
	newNode->data = val;
	Node* temp = l.head;
	for (int i=0; i<pos-1; i++){
		if (temp->next != NULL)
			temp = temp->next;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next = newNode;
}

void print(DLinkedList l){
	Node* temp = l.head;
	while (temp != NULL)
	{
		cout << temp->data<< "<->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void reverse_list(DLinkedList& l){
	if (l.head == NULL || l.head->next == NULL)
		return;
	Node* prev = NULL;
	Node* cur = l.head;
	Node* next = NULL;
	while (cur != NULL){
		next = cur->next;
		cur->next = prev;
		cur->prev = next;
		prev = cur;
		cur = next;
	}
	l.head = prev;
}

int main(){
	DLinkedList listt;
//	push_front(listt, 1);
//	push_front(listt, 2);
//	push_front(listt, 3);

	push_back(listt, 1);
	push_back(listt, 2);
	push_back(listt, 3);
//	pop_front(listt);
//	pop_back(listt);
	insertt(listt, 9, 7);
	print(listt);
	reverse_list(listt);
	print(listt);

	return 0;
}
