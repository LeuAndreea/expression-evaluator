#include "ExpressionEvaluator.h"

#include <iostream>
using namespace std;
ExpressionEvaluator::ExpressionEvaluator(string expression)
{
	this->expression = expression;
	this->eliminateSpaces();
	if (!this->checkExpression())
		throw Exception("Expression not in right format !");
}
string ExpressionEvaluator::eliminateSpaces()
{
	this->expression.erase(remove(this->expression.begin(), this->expression.end(), ' '), this->expression.end());
	//cout << this->expression;
	return this->expression;
}
bool ExpressionEvaluator::checkExpression()
{
	string characters = "0123456789()+-/*^$";
	for (int i = 0; i < this->expression.size(); i++) {
		if (characters.find(this->expression[i]) == string::npos) {
			return false;
		}
	}
	return true;
}
Queue ExpressionEvaluator::convertToPostfix()
{
	Queue result;
	Stack operands;

	string s = this->expression;
	for (int i = 0; i < this->expression.size(); i++) {
		string aux(1, s[i]);
		if (s[i] >= 48 && s[i] <= 57) {
			while (s[i + 1] >= 48 && s[i + 1] <= 57) {
				i += 1;
				aux += s[i];
			}
			result.push(aux);
		}
		else if (s[i] == '(')
			operands.push(aux);
		else if (s[i] == ')') {
			while (operands.getTop() != "(" && !(operands.isEmpty())) {
				result.push(operands.getTop());
				operands.pop();
			}
			operands.pop();
		}
		else {
			while (!operands.isEmpty()) {
				if (getPrecedence(s[i]) <= getPrecedence(operands.getTop()[0])) {
					result.push(operands.getTop());
					operands.pop();
				}
				else 
					break;
				
			}
			operands.push(aux);
		}
		//cout << "queue: " << endl;
		//result.printQueue();
		//cout << "stack: " << endl;
		//operands.printStack();

	}
	while (!operands.isEmpty()) {
		result.push(operands.getTop());
		operands.pop();
	}
	//result.printQueue();
	return result;
	//cout << "queue: " << endl;
	//result.printQueue();
	//cout << "stack: " << endl;
	//operands.printStack();

	
}

string ExpressionEvaluator::EvaluatePostFix(Queue q)
{
	q.printQueue();
	cout << "evaluate post fix" << endl;
	Stack result;
	while (!q.isEmpty()) {
		if (q.top()[0] >= 48 && q.top()[0]<=57) 
			result.push(q.top());
			
		else {
			int nr2 = stoi(result.getTop());
			result.pop();
			int nr1 = stoi(result.getTop());
			result.pop();
			if (q.top() == "$") {
				result.push(to_string(2 * nr1 + 3 * nr2));
			}
			else if(q.top() == "^") {
				cout << "pow" << endl;
				cout << pow(nr1, nr2) << endl;
				result.push(to_string((int)(pow(nr1, nr2))));
			}
			else if (q.top() == "*")
				result.push(to_string(nr1*nr2));
			else if (q.top() == "/")
				result.push(to_string(nr1 / nr2));
			else if (q.top() == "+")
				result.push(to_string(nr1 + nr2));
			else  
				result.push(to_string(nr1 - nr2));
		}
		q.pop();
		cout << "RESULT" << endl;
		result.printStack();
		cout << "QUEUE" << endl;
		q.printQueue();
	}
	return result.getTop();
}

int ExpressionEvaluator::computeResult()
{
	Queue q = this->convertToPostfix();
	cout << "POSTFIX VERSION:" << endl;
	q.printQueue();
	cout << "after postfix" << endl;
	string s = this->EvaluatePostFix(q);
	
	return stoi(s);
}

int ExpressionEvaluator::getPrecedence(char c)
{
	if (c == '4')
		return 4;
	if (c == '^')
		return 3;
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	if (c == '(')
		return 0;
}
