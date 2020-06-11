#pragma once
class Node
{
public:
	Node();
	Node(int address);
	~Node();

	int data;
	Node* next = nullptr;
	Node* prev = nullptr;
};