#include "Stack.h"
#include "Queue.h"
#include "test.h"
#include "Exceptions.h"
#include "ExpressionEvaluator.h"
#include <iostream>
#include <assert.h>
//#include <exception>


void testStack() {
	Stack s;
	//testing isEmpty when list is empty
	assert(s.isEmpty() == true);
	//testing pop when stack is empty
	try {
		s.pop();}
	catch (Exception &ex) {
		assert(ex.getError() == "Stack is empty!");
	}
	//testing top when stack is empty
	try {
		s.getTop();}
	catch (Exception &ex) {
		assert(ex.getError() == "Stack is empty!");
	}
	//pushing element to stack
	s.push("3");
	//testing isEmpty when stack has els
	assert(s.isEmpty() == false);
	//testing top function
	assert(s.getTop() == "3");
	s.push("5");
	assert(s.getTop() == "5");
	s.pop();
	s.pop();
	//testing pop and top after deleting all elements from stack
	try {
		s.pop();}
	catch (Exception &ex) {
		assert(ex.getError() == "Stack is empty!");
	}

	try {
		s.getTop();}
	catch (Exception &ex) {
		assert(ex.getError() == "Stack is empty!");
	}
	s.push("9");
}

void testQueue() {
	Queue q;
	//testing if queue empty when creating
	assert(q.isEmpty() == true);
	//testing pop and top when queue is empty
	try {
		q.pop();
	}
	catch (Exception &ex) {
		assert(ex.getError() == "Queue is empty!");
	}

	try {
		q.top();
	}
	catch (Exception &ex) {
		assert(ex.getError() == "Queue is empty!");
	}
	//testing pushing element in empty queue
	q.push("3");
	assert(q.isEmpty() == false);
	assert(q.top() == "3");
	//testing popping element
	q.pop();
	assert(q.isEmpty() == true);

	q.push("5");
	assert(q.top() == "5");
	q.push("3");
	assert(q.top() == "5");
	q.pop();
	assert(q.top() == "3");
	q.push("6");
	q.push("12");
	q.push("33");
	q.push("323");
	q.push("11");
	q.push("22");
	q.push("6");
	q.push("7");
	q.push("12");
	//q.push(13);
	q.pop();
	assert(q.top() == "6");
	q.pop();
	assert(q.top() =="12");
	q.pop();
	assert(q.top() =="33");
	q.push("33");
	q.pop();
	assert(q.top() == "323");
}

void testExprEvaluator() {
	ExpressionEvaluator expr=ExpressionEvaluator("1+2*(3-4/(5+6))+7");
	//cout << expr.computeResult();
	//assert(expr.computeResult() == 14);
	ExpressionEvaluator expr2 = ExpressionEvaluator("(1+1)^2$2-7");
	cout << expr2.computeResult() << endl;
	assert(expr2.computeResult() == 1017);
}

void testAll() {
	testStack();
	testQueue();
	testExprEvaluator();
}