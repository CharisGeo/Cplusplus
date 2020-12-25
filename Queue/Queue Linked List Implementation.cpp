/* Array implementation has a limitation: fixed size.
If array gets filled deny enqueue or create a new array and copy data which is costly.
Also the array might have unused memory.
*/
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* front = nullptr;
Node* rear = NULL;

void Enqueue(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	if (front == NULL && rear == NULL)
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
}

void Dequeue()
{
	Node* temp = new Node();
	if (front == NULL)
	{
		return;
	} 
	if (front == rear)
	{
		front == NULL;
		rear = NULL;
	}
	else
	{
		front = front->next;
	}
	delete (temp);
}

int main()
{
	Enqueue(2);
	Enqueue(5);
	Enqueue(10);
	Dequeue();
}