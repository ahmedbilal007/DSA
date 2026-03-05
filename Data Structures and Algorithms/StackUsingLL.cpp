#include <iostream>
#include <list>
using namespace std;
class Stack{
	list<int> l;
public:
	void push(int val){
		l.push_front(val);
	}
	void pop(){
		l.pop_front();
	}
	int top(){
		return l.front();
	}
	bool isEmpty(){
		return l.empty();
	}
};
int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << s.top() << endl;
	cout << s.isEmpty() << endl;
	while (!s.isEmpty()){
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}
