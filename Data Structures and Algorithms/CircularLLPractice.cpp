#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next = NULL;
};

struct CircularList{
	Node *head = NULL;
	Node *tail = NULL;
};

void insertAtHead(CircularList& l, int val){
	Node* newNode = new Node();
	newNode->data = val;
	if (l.head == NULL){
		l.head = l.tail = newNode;
		l.tail->next = l.head;
		return;
	} else {
		newNode->next = l.head;
		l.head = newNode;
		l.tail->next = l.head;
	}
}

void insertAtTail(CircularList& l, int val){
	Node* newNode = new Node();
	newNode->data = val;
	if (l.head == NULL || l.tail == NULL){
		l.head = l.tail = newNode;
		l.tail->next = l.head;
		return;
	} else {
		l.tail->next = newNode;
		newNode->next = l.head;
		l.tail = newNode;
	}
}

void deleteAtHead(CircularList& l){
	if (l.head == NULL){
		cout << "Linked List is empty.\n";
		return;
	}
	if (l.head == l.tail){
		delete l.head;
		l.head = l.tail = NULL;
		return;
	}
	Node* temp = l.head;
	l.head = l.head->next;
	l.tail->next = l.head;
	temp->next = NULL;
	delete temp;
}

void deleteAtTail(CircularList& l){
	if (l.head == NULL){
		cout << "Linked List is empty.\n";
		return;
	}
	if (l.head == l.tail){
		delete l.head;
		l.head = l.tail = NULL;
		return;
	}
	Node* temp = l.tail;
	Node* prev = l.head;
	while (prev->next != l.tail)
		prev = prev->next;

	l.tail = prev;
	prev->next = l.head;
	temp->next = NULL;
	delete temp;
}

void print_list(CircularList l){
	if (l.head == NULL || l.tail == NULL){
		cout << "Linked List is empty.\n";
		return;
	}
	cout << l.head->data << "->";
	Node* temp = l.head->next;
	while (temp != l.head){
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << l.head->data;
}


int main(){
	CircularList l;
	insertAtTail(l,1);
	insertAtTail(l,2);
	insertAtTail(l,3);
	insertAtTail(l,4);

	deleteAtHead(l);
	deleteAtTail(l);

	print_list(l);
	return 0;
}




