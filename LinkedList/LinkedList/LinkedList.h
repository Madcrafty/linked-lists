#pragma once
#include "Node.h"
class LinkedList {
public:
	LinkedList(int Value);
	~LinkedList();

	int read(int value);
	void pushFront(int value);
	void pushBack(int value);
	void insert(int iterator, int value);
	void begin();
	void end();
	Node* first();
	Node* last();
	int count();
	void erase(int iterator);
	void remove(int value);
	void popBack();
	void popFront();
	bool empty();
	void clear();
protected:
	Node* HeadNode;
	Node* TailNode;
	int iterator;
};