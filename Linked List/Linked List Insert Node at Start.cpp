/* Arrays:
1. Stored as a contiguous block of memory - we know the address of all elements
2. Constant time when accessing an element - O(1) Time Complexity
3. Fixed size - can have unused memory
4. If array is full and need more elements no other option than to create a new array
double the size and copy the content from the previous array
5. Cost of inserting/deleting an element at beginning is O(n) - shift each element one position to higher index
6. Cost of inserting/deleting an element at end is O(1) if array is not full otherwise O(n) if array is full
7. Cost of inserting/deleting an element at ith position is O(n) - shifting of elements

Linked Linst:
1. Multiple blocks of memory at different addresses
2. Node that has two fields one to store the data and one to store the address of the next node
3. First node called the head node
4. If n is the number of elements in the linked list cost of accessing an element is 0(n)
5. No unused memory but extra memory needed for pointer variables
6. Cost of inserting/deleting an element at beginning is O(1) - create a new head node and adjust the head pointer
7. Cost of inserting/deleting an element at end is O(n) - traverse whole list then create new node and adjust links
8. Cost of inserting/deleting an element at ith position is O(n) - traverse list then create new node and adjust links
*/
//Linked List: Inserting node at the beginning
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head; // global variable

void Insert(int x)
{
    Node* temp = new Node; //points to address of new node
    temp->data = x;
    temp->next = NULL; //if list is empty node link is null
    if (head != NULL) temp->next = head; //if list is not empty update node link
    head = temp; // head now pointing to the address of the new node if list is empty
}

void Print()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    head = nullptr; // empty list
    cout << "Enter node number: " << endl;
    int n, i, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter node value: " << endl;
        cin >> x;
        Insert(x);
        Print();
    }
    return 0;
}