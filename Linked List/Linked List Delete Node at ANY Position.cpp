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

void Insert(int data,int n) 
{
	Node* temp1 = new Node;
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

void Delete(int n) // Delete node at n position
{
	Node* temp1 = head;
	if (n == 1)
	{
		head = temp1->next; // head now points to second node
		delete(temp1);
		return;
	}
	for (int i = 0; i < n - 2; i++)
	{
		temp1 = temp1->next;
	}
	Node* temp2 = temp1->next; //nth node - node to be deleted
	temp1->next = temp2->next; //set link of (n-1)th node to the link of nth node which points to n+1 node
	delete(temp2);
}
//SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
//	if (position == 0) { return head->next; }
//	head->next = deleteNode(head->next, position - 1);
//	return head;
//}

void Print()
{
	Node* temp = head;
	if (temp != NULL)
	{
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Insert(2,1);
	Insert(4,2);
	Insert(6,2);
	Insert(5,3); 
	Print();
	int n;
	cin >> n;
	Delete(n);
	Print();
}