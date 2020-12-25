//Reverse a Linked List: Iterative Method
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* Reverse(struct Node* head) //traverse list and reverse links
{
	Node* current = head; //stores address of current node
	Node* prev = NULL; //stores address of previous node
	Node* next; //stores address of next node
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

Node* Insert(Node* head, int data)
{
	Node* temp = new Node;
	temp->next = NULL;	
	temp->data = data;
	if (head == NULL)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		Node* temp2 = head;
		while (temp2 != NULL)
		{
			temp2 = temp2->next;
		}
		temp->next = temp2->next;
		temp2->next = temp;
	}
	return head;
}

void Print(Node* head)
{
	if (head != NULL)
	{
		cout << head->data;
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	Print(head);
	head = Reverse(head);
	Print(head);
}