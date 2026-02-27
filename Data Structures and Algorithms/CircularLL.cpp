#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next = NULL;
};

struct CircularLL{
	Node* head = NULL;
	Node* tail = NULL;
};

void insertAtHead(CircularLL& l, int val){
	// Using head pointer (if given in the list)

	Node* newNode = new Node();
	newNode->data = val;
	if (l.head == NULL){
		l.head = l.tail = newNode;
		l.tail->next = l.head;			// condition for circular
		return;
	} else {
		newNode->next = l.head;
		l.head = newNode;
		l.tail->next = l.head;
	}

	// Using tail pointer (if head is not given)


//	if (l.tail == NULL){
//		l.tail = newNode;
//		l.tail->next = l.tail;
//		return;
//	} else {
//		newNode->next = l.tail->next;
//		l.tail->next = newNode;
//	}
}

void insertAtTail(CircularLL& l, int val){
	Node* newNode = new Node();
	newNode->data = val;
	if (l.head == NULL){
		l.head = l.tail = newNode;
		l.tail->next = newNode;
	} else {
		newNode->next = l.head;
		l.tail->next = newNode;
		l.tail = newNode;
	}
}

void print(CircularLL l){
	// Using head pointer
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
	cout << l.head->data << endl;

	// Using tail Pointer (head is not given)


//	Node* temp = l.tail->next;					// points to the first element in the list
//	cout << temp->data << "->";
//	Node* temp2 = temp->next;					// points to the next element of the first that iterates over the list to print the remaining values
//	while (temp2 != head){
//		cout << temp2->data << "->";
//		temp2 = temp2->next;
//	}
//	cout << temp->data << endl;					// to verify whether list is circular or not.
}

void deleteAtHead(CircularLL& l){
	if (l.head == NULL){
		cout << "Linked List is empty.\n";
		return;
	}
	if (l.head == l.tail){
		// If there is only one element(Node) in the list;
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

void deleteAtTail(CircularLL& l){
	if (l.head == NULL || l.tail == NULL){
		cout << "Linked list is empty.\n";
		return;
	} else if (l.head == l.tail){
		delete l.head;
		l.head = l.tail = NULL;
		return;
	} else {
		Node* temp = l.tail;
		Node* prev = l.head;
		while(prev->next != l.tail)
			prev = prev->next;
		l.tail = prev;
		prev->next = l.head;
		temp->next = NULL;
		delete temp;
	}
}



int main(){
	CircularLL listt;
	insertAtHead(listt, 1);
	insertAtHead(listt, 2);
	insertAtHead(listt, 3);
	insertAtTail(listt, 4);
	deleteAtHead(listt);
	deleteAtTail(listt);
	print(listt);



	return 0;
}
