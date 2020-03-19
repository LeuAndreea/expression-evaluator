#pragma once
#include "Exceptions.h"
#include <stddef.h>
#include <string>
typedef string Telement;

using namespace std;
class Node {
	private:
		Telement info;
		Node *next;
	public:
		Node() {};
		~Node() {};
	friend class Stack;
};

class Stack {
	private:
		Node* top;
	public:
		/*Description: creates a new empty stack
		Pre: True
		Post: s ∈  S, s is an empty stack */
		Stack();
		/*Description: destroys a stack
		Pre: s ∈ S
		Post: s was destroyed*/
		~Stack();
		/*Description: pushes(adds) a new element onto the stack
		Pre : s ∈ S, e is a TElem
		Post : s’ ∈ S, s’ = s + e, e is the most recent element added to the stack*/
		void push(Telement e);
		/*Description: pops(removes) the most recent element from the stack
		Pre : s ∈ S, s is not empty
		Post : pop  e, e is a TElem, e is the most recent element from s, s’ ∈ S, s’ = s - e
		Throws : an underflow error if the stack is empty */
		void pop();
		/*Description: returns the most recent element from the stack(but it does not change the stack) .
		Pre : s ∈ S, s is not empty
		Post : top ← e, e is a TElem, e is the most recent element from s Throws : an underflow error if the stack is empty*/
		Telement getTop();
		/*Description: checks if the stack is empty(has no elements)
		Pre : s ∈ S
		Post : true if s has no elements, false otherwise*/
		bool isEmpty();

		void printStack();









};