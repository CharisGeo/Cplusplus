#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head = NULL;

Node* GetNewNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void InsertAtHead(int x)
{
	Node* newNode = GetNewNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}


void Print()
{
	Node* temp = head;
	cout << "Forward: ";
	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

void ReversePrint() {
	Node* temp = head;
	if (temp == NULL)
	{
		return;
	}
	cout << "Reverse: ";
	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->prev;
	}
	cout << endl;
}

int main()
{
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
}