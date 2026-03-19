#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<char> v;
public:
    void push(char val)
    {
        v.push_back(val);
    }
    char pop()
    {
        return top();
    }
    char top()
    {
        return v[v.size()-1];
    }
    bool empty()
    {
        if (v.size()==0)
            return true;
        return false;
    }
};
bool isOperator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/';
}
int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
string infixToPostFix(string infix, Stack s)
{
    int i = 0;
    string postfix = "";
    while (i < infix.length())
    {
        if (isspace(infix[i]))
        {
            i++;
            continue;
        }
        if (isdigit(infix[i]))
        {
            postfix += infix[i++];
            postfix += " ";
            continue;
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += char(s.pop());
                postfix += " ";
            }
            s.pop();
        }
        else if (isOperator(infix[i]))
        {
            while (!s.empty() && precedence(s.top()) >= precedence(infix[i]))
            {
                postfix += char(s.top());
                postfix += " ";
            }
            s.push(infix[i]);
        }
        i++;
    }
    while (!s.empty()){
		postfix += char(s.pop());
		postfix += " ";
    }
    return postfix;
}

int main()
{
	Stack s;
	string infix = "2+3-5*6+(8/2)^2";

	cout << infixToPostFix(infix, s) << endl;
}
