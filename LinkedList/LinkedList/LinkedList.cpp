// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
Node HeadNode;
Node TailNode;
int iterator;
void pushFront(int value) {
	Node new_node;
	new_node.data = value;
	Node temp = first();
	new_node.next = &temp;
}
void pushBack(int value) {
	Node new_node;
	new_node.data = value;
	Node temp = first();
	new_node.prev = &temp;
}
void insert(int iterator, int value) {
	Node new_node;
	new_node.data = value;
	Node temp = first();
	for (size_t i = 0; i < iterator; i++)
	{
		temp = *temp.next;
	}
	Node nextTemp = *temp.next;
	new_node.next = &nextTemp;
	new_node.prev = &temp;
}
int begin() {
	iterator = 0;
}
int end() {
	iterator = count();
}
Node first() {
	return HeadNode;
}
Node last() {
	return TailNode;
}
int count() {
	int i = 0;
	Node temp = first();
	while (temp.next != nullptr)
	{
		temp = *temp.next;
		i++;
	}
	return i;
}
void erase(int iterator) {
	Node temp = first();
	for (size_t i = 0; i < iterator; i++)
	{
		temp = *temp.next;
	}
	delete &temp;
}
void remove(int value) {
	Node temp = first();
	for (size_t i = 0; i < iterator; i++)
	{
		if (temp.data == value)
		{
			if (temp.prev == HeadNode.prev)
			{
				HeadNode = *temp.next;
			}
			if (temp.next == TailNode.next)
			{
				TailNode = *temp.prev;
			}
			delete& temp;
		}
		temp = *temp.next;
	}
	
}
void popBack() {
	Node temp = *TailNode.prev;
	delete& TailNode;
	TailNode = temp;
}
void popFront() {
	Node temp = *HeadNode.next;
	delete& HeadNode;
	HeadNode = temp;
}
bool empty() {
	if (count() == 0)
	{
		return true;
	}
	return false;
}
void clear() {
	Node temp = HeadNode;
	while (temp.next == nullptr)
	{
		temp = *temp.next;
		delete temp.prev;
	}
	delete& temp;
}
int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
