#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack()
{
	this->top = NULL;

}
Stack::~Stack()
{
	//Node *n = this->top;
	//while (n!= NULL) {
	//	Node *m = n;
	//	n = n->next;
	//	delete[]m;
	//}
	//delete[]n;
}

void Stack::push(Telement e)
{
	Node *n = NULL;
	n = new Node;
	n->info = e;
	if (!(this->isEmpty()))
		n->next = this->top;
	else
		n->next = NULL;
	this->top = n;
}

void Stack::pop()
{
	if (this->isEmpty()==true)
		throw Exception("Stack is empty!");
	Node *n = this->top;
	this->top = this->top->next;
	//delete[]n;
	
}

Telement Stack::getTop()
{
	if (this->isEmpty())
		throw Exception("Stack is empty!");
	return this->top->info;
}

bool Stack::isEmpty()
{
	if (this->top == NULL)
		return true;
	return false;
}

void Stack::printStack()
{
	Node *n = this->top;
	while (n != NULL) {
		cout << n->info << " ";
		n = n->next;
	}
	cout << endl;
}
