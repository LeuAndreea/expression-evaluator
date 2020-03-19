#pragma once
#include "Exceptions.h"

#include <stddef.h>
#include <string>
#include <vector>




class Queue {
	private:
		int size,capacity,nextEmpty, front, rear;
		vector<string> elems;
		int *next;
public:
		/*Description : creates a new empty queue
		Pre : True
		Post : q ∈ Q, q is an empty queue*/
		Queue();
		/*Description: destroys a queue
		Pre : q ∈ Q
		Post : q was destroyed*/
		~Queue();
		/*Description: pushes(adds) a new element to the rear of the queue
		Pre : q 2 Q, e is a TElem
		Post : q∈ 2 Q, q’ = q + e, e is the element at the rear of the queue*/
		void push(string e);
		/*Description: pops(removes) the element from the front of
		the queue
		Pre : q ∈ Q, q is not empty
		Post : pop  e, e is a TElem, e is the element at the front of q, q’ ∈ Q, q’ = q - e
		Throws : an underfl	ow error if the queue is empty*/
		void pop();
		/*Description: returns the element from the front of the queue(but it does not change the queue)
		Pre : q ∈ Q, q is not empty
		Post : top  e, e is a TElem, e is the element from the front of q
		Throws : an underflow error if the queue is empty*/
		string top();
		/*Description: checks if the queue is empty(has no elements)
		Pre : q ∈ Q
		Post : isEmpty  true if s has no elements, false otherwise*/
		bool isEmpty();
		void resize();

		void printQueue();




};