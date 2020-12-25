//Linked List: Insert node at any position
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

void Insert(int data, int n)
{
	Node* temp1 = new Node;
	temp1->data = data;
	temp1->next = nullptr;

	if (n == 1)
	{
		temp1->next = head; // set link of newly created node to head link - now points to null
		head = temp1; // set head link to newly created node - now points to memory address of newly created first node
		return;
	}

	Node* temp2 = head;
	for (int i = 0; i < n - 2; i++) //need to go to n-1 node
	{
		temp2 = temp2->next; //end at the link of node n-1
	}
	temp1->next = temp2->next; //set link field of newly created node to this n-1 node
	temp2->next = temp1; //set link of n-1 node to point to new node
}
//SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
//	SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
//	newNode->data = data;
//	newNode->next = NULL;
//	if (position == 1)
//	{
//		newNode->next = head->next;
//		head = newNode;
//		return head;
//	}
//	SinglyLinkedListNode* tailNode = head;
//	for (int i = 0; i < position - 1; i++)
//	{
//		tailNode = tailNode->next;
//	}
//	newNode->next = tailNode->next;
//	tailNode->next = newNode;
//	return head;
//}

void Print()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->next; // move to next node
	}
	cout << endl;
}

int main()
{
	Insert(2, 1);
	Insert(3, 2);
	Insert(4, 1);
	Insert(5, 2);
	Print();
}