#include <iostream>
#include "LinkedList.h"
void display(LinkedList* list) {
    int length = list->count();
    for (size_t i = 0; i < length; i++)
    {
        std::cout << list->read(i) << std::endl;
    }
}
int main()
{
    LinkedList nuble = LinkedList(1);
    nuble.pushFront(0);
    nuble.pushBack(2);
    display(&nuble);
}