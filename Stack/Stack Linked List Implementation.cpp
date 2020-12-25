/* Linked list implementation of stack
Do not have to worry about memory - we use dynamic memory
*/
#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

Node* top = NULL;

void Push(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->link = top;
	top = temp;
}

void Pop()
{
	Node* temp;
	if (top == NULL)
	{
		return;
	}
	temp = top;
	top = top->link;
	delete(temp);
}

void Print()
{
	cout << "Stack: ";
	while (top != NULL)
	{
		cout << top->data;
		top = top->link;
	}
	cout << endl;
}

int main() {
	Push(2); Print();
	Push(5); Print();
	Push(10); Print();
	Pop(); Print();
	Push(12); Print();
}