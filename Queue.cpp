#include "Queue.h"

#include <iostream>
Queue::Queue()
{
	this->elems.resize(10);
	this->capacity = 10;
	this->next = new int[100];
	this->nextEmpty = 0;
	for (int i = 0; i < this->capacity - 1; i++) {
		this->next[i] = i + 1;
	}
	next[this->capacity-1] = -1;


}

Queue::~Queue()
{
	
//	delete[]this->next;
}

void Queue::push(string e)
{
	if (this->nextEmpty == -1) {
		this->resize();
		
	}

	int poz = this->nextEmpty;
	
	this->elems[poz] = "";
	for (int i = 0; i < e.size(); i++)
		this->elems[poz] += e[i];
	this->size ++;
	this->rear = poz;
	this->nextEmpty = this->next[poz];
	//cout << "After pushing: " << e <<endl;
	//cout << "head " << this->front << "  rear " << this->rear << "next empty  " << this->nextEmpty << endl;
	//for (int i = 0; i < this->capacity; i++) 
	//	cout <<i << "  " << this->elems[i] << "  " << this->next[i] << endl;
	
	
}

void Queue::pop()
{
	if (this->isEmpty() == true)
		throw Exception("Queue is empty!");

	if (this->size == 1) {
		this->size--;
		this->nextEmpty = this->front;
	}
	else {
		this->elems[front] = "";
		int poz = this->front;
		this->front = this->next[this->front];
		this->next[rear] = poz;
		this->next[poz] = this->nextEmpty;
		this->nextEmpty = poz;
		this->size--;
	}
	//cout << "After:popping " << endl;
	//cout << "head " << this->front << "  rear " << this->rear <<  "next empty  " << this->nextEmpty<< endl;
	//for (int i = 0; i < this->capacity; i++) 
	//cout << i << "  " <<this->elems[i] << "  " << this->next[i] << endl;
}

string Queue::top()
{
	if (this->isEmpty() == true)
		throw Exception("Queue is empty!");
	return this->elems[this->front];
}

bool Queue::isEmpty()
{
	if (this->size == 0)
		return true;
	return false;
}

void Queue::resize()
{
	this->next[this->rear] = this->nextEmpty=this->capacity;
	this->elems.resize(capacity*2);
	
	int *newNext = new int[this->capacity*2];
	for (int i = 0; i < this->size; i++) 
 		newNext[i] = this->next[i];
	
	delete[] this->next;
	this->next = newNext;
	
	for (int i = this->capacity; i < this->capacity * 2 - 1; i++) {
		this->next[i] = i + 1;
	}
	this->capacity *= 2;
	next[this->capacity - 1] = -1;
	
}



void Queue::printQueue()
{
	int i = this->front;
	while (i != -1) {
		cout << this->elems[i] << endl;
		i = this->next[i];
	}
	cout << endl;
}
