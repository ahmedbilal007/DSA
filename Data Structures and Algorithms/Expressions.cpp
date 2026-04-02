#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Stack
{
public:
	vector<char> v;
	void push(char ch)
	{
		v.push_back(ch);
	}
	void pop()
	{
		v.pop_back();
	}
	int top()
	{
		return v.size() - 1;
	}
	bool empty(){
		return (v.size() == 0);
	}
	char peek()
	{
		return v[top()];
	}
};

bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
int precedence(char ch)
{
	if (ch == '^')
		return 3;
	if (ch == '*' || ch == '/')
		return 2;
	if (ch == '+' || ch == '-')
		return 1;
	return 0;
}

string infixToPostFix(string exp, Stack s){
	int i = 0;
	string postFix = "";
	while (i < exp.length()){
		if (isspace(exp[i])){
			i++;
			continue;
		}
		if (isalnum(exp[i])){
			string num = "";
			while (i<exp.length() && isalnum(exp[i]))
			{
				num += exp[i++];
			}
			postFix += num;
			postFix += " ";
			continue;
		} else if (exp[i] == '('){
			s.push('(');
		} else if (exp[i] == ')'){
			while (!s.empty() && s.peek() != '('){
				postFix += s.peek();
				postFix += " ";
				s.pop();
			}
			s.pop();
		} else if (isOperator(exp[i])){
			while (!s.empty() && precedence(s.peek()) >= precedence(exp[i]))
			{
				postFix += s.peek();
				postFix += " ";
				s.pop();
			}
			s.push(exp[i]);
		} else if (exp[i] == '^'){
			s.push(exp[i]);
		}
		i++;
	}
	while (!s.empty()){
		postFix += s.peek();
		postFix += " ";
		s.pop();
	}
	return postFix;
}

string reverseExp(string exp){
	string reversed = "";
	for (int i=0; i<exp.length(); i++){
		if (exp[i] == '(')
			reversed += ')';
		else if (exp[i] == ')')
			reversed += '(';
		else 
			reversed += exp[i];
	}
	return reversed;
}

string infixToPrefix(string exp, Stack s){
	string reversed = reverseExp(exp);
	string preFix = "";
	int i = 0;
	while (i < reversed.length()){
		if (isspace(reversed[i])){
			i++;
			continue;
		}
		if (isalnum(reversed[i])){
			string num = "";
			while (i<reversed.length() && isalnum(reversed[i]))
			{
				num += reversed[i++];
			}
			preFix += num;
			preFix += " ";
			continue;
		} else if (reversed[i] == '('){
			s.push('(');
		} else if (reversed[i] == ')'){
			while (!s.empty() && s.peek() != '('){
				preFix += s.peek();
				preFix += " ";
				s.pop();
			}
			s.pop();
		} else if (isOperator(reversed[i])){
			if (reversed[i] == '^'){
				while (!s.empty() && precedence(s.peek()) >= precedence(reversed[i]))
				{
					preFix += s.peek();
					preFix += " ";
					s.pop();
				}
			} else {
				while (!s.empty() && precedence(s.peek()) > precedence(reversed[i])){
					preFix += s.peek();
					preFix += " ";
					s.pop();
				}
			}
			s.push(reversed[i]);
		}
		i++;
	}
	while (!s.empty())
	{
		preFix += s.peek();
		preFix += " ";
		s.pop();
	}
	reverse(preFix.begin(), preFix.end());
	return preFix;
}

int main(){
	Stack s;
	cout << "Converting an infix into postfix expression.\n";
	cout << infixToPostFix("A^B^C", s);
	cout << "\nConverting an infix into prefix expression.\n";
	cout << infixToPrefix("(A+B)-C*(R-M)/T^F", s);
	return 0;
}