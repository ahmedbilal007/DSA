#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next = NULL;
};

struct CQueue{
	Node* frontt = NULL;
	Node* rear = NULL;
};

void enqueue(CQueue& q, int x){
	Node* newNode = new Node();
	newNode->data = x;
	if (q.frontt == NULL || q.rear == NULL){
		q.frontt = q.rear = newNode;
		q.rear->next = newNode;
	} else {
		q.rear->next = newNode;
		q.rear = newNode;
		newNode->next = q.frontt;
	}
}

void dequeue(CQueue& q){
	if (q.frontt == NULL || q.rear == NULL){
		cout << "Queue is empty.\n";
		return;
	} else if (q.frontt == q.rear){
		Node* temp = q.rear;
		q.frontt = q.rear = NULL;
		delete temp;
	} else {
		Node* temp = q.frontt;
		q.frontt = q.frontt->next;
		q.rear->next = q.frontt;
		delete temp;
	}
}

void display(CQueue q){
	cout << q.frontt->data << " ";
	Node* temp = q.frontt->next;
	while (temp != q.frontt){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << q.frontt->data << endl;
}

int peek(CQueue q){
	if (q.frontt == NULL || q.rear == NULL){
		cout << "Queue is empty.\n";
	} else {
		return q.frontt->data;
	}
}

int main(){
	CQueue q;
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	display(q);
	dequeue(q);
	dequeue(q);
	display(q);
	enqueue(q, 6);
	enqueue(q, 7);
	display(q);
	cout << peek(q) << endl;

	return 0;
}
