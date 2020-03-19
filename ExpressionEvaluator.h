#pragma once
#include "Queue.h"
#include "Stack.h"

#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
class ExpressionEvaluator {
private:
	string expression;
	
	static int getPrecedence(char c);
public:
	ExpressionEvaluator(string expression);
	string eliminateSpaces();
	bool checkExpression();
	Queue convertToPostfix();
	string EvaluatePostFix(Queue q);
	int computeResult();



};