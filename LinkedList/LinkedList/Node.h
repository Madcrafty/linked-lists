#pragma once
class Node
{
public:
	Node();
	Node(int address);
	~Node();

	int data = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};