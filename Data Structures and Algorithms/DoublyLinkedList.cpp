#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* prev = NULL;
	Node* next = NULL;
};

struct DLinkedList{
	Node* head = NULL;
	Node* tail = NULL;
};

void push_front(DLinkedList& l, int val){
	Node* newNode = new Node();
	newNode->data = val;
	if (l.head == NULL){
		l.head = l.tail = newNode;
		return;
	} else {
		newNode->next = l.head;
		l.head->prev = newNode;
		l.head = newNode;
	}
}

void push_back(DLinkedList& l, int val){
	Node* newNode = new Node();
	newNode->data = val;
	if (l.head == NULL){
		l.head = l.tail = newNode;
		return;
	} else {
		l.tail->next = newNode;
		newNode->prev = l.tail;
		l.tail = newNode;
	}
}

void pop_front(DLinkedList& l){
	if (l.head == NULL){
		cout << "Linked List is empty.\n";
		return;
	}
	Node* temp = l.head;
	l.head = l.head->next;
	if (l.head != NULL)
		l.head->prev = NULL;
	temp->next = NULL;
	delete temp;
}

void pop_back(DLinkedList& l){
	Node* temp = l.tail;
	if (l.head == NULL){
		cout << "Linked List is empty.\n";
		return;
	}
	l.tail = l.tail->prev;
	if (l.tail != NULL)
		l.tail->next = NULL;
	temp->prev = NULL;
	delete temp;
}

void insert(DLinkedList& l, int val, int pos){
	if (pos == 0){
		push_front(l,val);
		return;
	}
	if (pos < 0){
		cout << "Invalid Position.\n";
		return;
	}
	Node* newNode = new Node();
	newNode->data = val;
	Node* temp = l.head;
	for (int i=0; i<pos-1; i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next = newNode;
}

void deleteV(DLinkedList& l, int val){
	int index = 0;
	Node* temp = l.head;
	while (temp != NULL){
		if (temp->data == val)
			break;
		temp = temp->next;
		index++;
	}
	temp = l.head;
	for (int i=0; i<index-1; i++){
		temp = temp->next;
	}
	Node* temp2 = temp->next;
	temp->next = temp2->next;
	temp2->prev = temp;
	delete(temp2);
}

void print_List(DLinkedList l){
	Node* temp = l.head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main(){
	DLinkedList listt;
	push_front(listt, 1);
	push_front(listt, 2);
	push_front(listt, 3);
	push_back(listt, 4);
	push_back(listt, 5);
	pop_front(listt);
	pop_back(listt);
	insert(listt, 6, 2);
	deleteV(listt,6);
	print_List(listt);
	return 0;
}
