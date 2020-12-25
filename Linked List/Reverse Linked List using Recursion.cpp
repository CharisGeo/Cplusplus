//Reverse a Linked List using Recursion
#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head = NULL;

Node* Insert(Node* head, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	if (head == NULL)
	{
		head = newNode;
	}
	else {
		Node* temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	return head;
}

void Print(Node* p)
{
	if (p == NULL)
	{
		return;
	}
	cout << p->data; //Print the value in the node
	Print(p->next); //Recursive Call
}

void Reverse(Node* p)
{
	if (p->next == NULL)
	{
		head = p;
		return;
	}
	Reverse(p->next); //Recursive Call
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
}
//SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
//	if (head->next == nullptr)
//	{
//		return head;
//	}
//	SinglyLinkedListNode* remaining = reverse(head->next);
//	SinglyLinkedListNode* q = head->next;
//	q->next = head;
//	head->next = nullptr;
//	return remaining;
//}

int main() {
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 5);
	Reverse(head);
	Print(head);
}