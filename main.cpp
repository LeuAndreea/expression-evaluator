#include "ExpressionEvaluator.h"
#include "test.h"
#include <iostream>
int main() {
	cout << "Press 0 when you want to exit." << endl;
	string s = "";
	while (s != "0") {
		cout << "Give expression:";
		getline(cin,s);
		try {
			ExpressionEvaluator expr=ExpressionEvaluator{ s };
			cout << expr.computeResult() << endl;
		}
		catch (Exception &ex) {
			cout << ex.getError() << endl;
		}
	}

	testAll();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}