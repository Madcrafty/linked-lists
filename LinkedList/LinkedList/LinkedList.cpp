#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList(int Value) {
	Node* new_node = new Node();
	new_node->data = Value;
	HeadNode = new_node;
	TailNode = new_node;
	iterator = 0;
}
LinkedList::~LinkedList() {

}
int LinkedList::read(int value) {
	Node* temp = first();
	for (size_t i = 0; i < value; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}
void LinkedList::pushFront(int value) {
	Node* new_node = new Node();
	new_node->data = value;
	Node* temp = first();
	new_node->next = temp;
	temp->prev = new_node;
	HeadNode = new_node;
}
void LinkedList::pushBack(int value) {
	Node* new_node = new Node();
	new_node->data = value;
	Node* temp = last();
	temp->next = new_node;
	TailNode = new_node;
}
void LinkedList::insert(int iterator, int value) {
	Node* new_node = new Node();
	new_node->data = value;
	Node* temp = first();
	for (size_t i = 0; i < iterator; i++)
	{
		temp = temp->next;
	}
	Node* nextTemp = temp->next;
	new_node->next = nextTemp;
	new_node->prev = temp;
	temp->next = new_node;
	nextTemp->prev = new_node;
}
void LinkedList::begin() {
	iterator = 0;
}
void LinkedList::end() {
	iterator = count();
}
Node* LinkedList::first() {
	return HeadNode;
}
Node* LinkedList::last() {
	return TailNode;
}
int LinkedList::count() {
	int i = 0;
	Node* temp = first();
	while (temp->next != nullptr)
	{
		temp = temp->next;
		i++;
	}
	i++;
	return i;
}
void LinkedList::erase(int iterator) {
	Node* temp = first();
	for (size_t i = 0; i < iterator; i++)
	{
		temp = temp->next;
	}
	temp->next->prev = temp->prev->next;
	temp->prev->next = temp->next->prev;
	delete &temp;
}
void LinkedList::remove(int value) {
	Node* temp = first();
	for (size_t i = 0; i < iterator; i++)
	{
		if (temp->data == value)
		{
			if (temp->prev == HeadNode->prev)
			{
				HeadNode = temp->next;
			}
			if (temp->next == TailNode->next)
			{
				TailNode = temp->prev;
			}
			temp->next->prev = temp->prev->next;
			temp->prev->next = temp->next->prev;
			delete& temp;
		}
		temp = temp->next;
	}
	
}
void LinkedList::popBack() {
	Node* temp = TailNode->prev;
	delete& TailNode;
	TailNode = temp;
	TailNode->next = nullptr;
}
void LinkedList::popFront() {
	Node* temp = HeadNode->next;
	delete& HeadNode;
	HeadNode = temp;
	HeadNode->prev = nullptr;
}
bool LinkedList::empty() {
	if (count() == 0)
	{
		return true;
	}
	return false;
}
void LinkedList::clear() {
	Node* temp = HeadNode;
	while (temp->next != nullptr)
	{
		temp = temp->next;
		if (temp->prev != nullptr)
			delete temp->prev;
	}
	delete& temp;
}