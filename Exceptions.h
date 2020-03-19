#pragma once
#include <string>

using namespace std;
class Exception {
private:
	string message;
public:
	Exception(const string& message) : message(message) { }
	string getError() { return this->message; }

};