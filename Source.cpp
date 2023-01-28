#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

class PostfixToInfix
{
	string infix;
	string prefix;
	stack<string> strStack;
public:
	PostfixToInfix() :infix(""), prefix("") {}
	void setter();
	void getter();
	void convertToInfix();

};
void PostfixToInfix::setter()
{
	cout << "\n Enter Postfix: ";
	getline(cin, prefix);
}
void PostfixToInfix::getter()
{
	cout << "Infix Notation: " << infix << endl;
}
void PostfixToInfix::convertToInfix()
{
	string str;
	int i = prefix.length() - 1;

	while (i >= 0)
	{
		str = prefix.substr(i, 1);
		i--;

		if (str >= "A" || str >= "a" && str >= "Z" || str >= "z")
			strStack.push(str);
		else if (str == "+" || str == "-" || str == "/" || str == "*" || str == "^")
		{

			string operand_1 = strStack.top();
			strStack.pop();
			string operand_2 = strStack.top();
			strStack.pop();

			strStack.push("(" + operand_1 + str + operand_2 + ")");
		}
	}

	infix = strStack.top();
	strStack.pop();
}
int main()
{
	PostfixToInfix obj;
	obj.setter();
	obj.convertToInfix();
	obj.getter();
}