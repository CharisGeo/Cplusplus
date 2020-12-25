/* Stack: A list with the restriction that insertion and deletion
can be performed only from the top.
Last In - First out
Insertion : Push()
Remove the most recent element: Pop()
Return element at top of the stack: Top()
Check if Stack is empty: IsEmpty()
Operations performed in constant time - 0(1)
Stack is used for:
1. Chain of Function Calls/Recursion
2. Implement undo operation in an editor
3. Check Balanced Parentheses
We can implement a stack using:
A) Arrays
b) Linked Lists
In case of overflow:
- Create a twice larger array and copy all elements in new array / cost is 0(n) where n is the no of elements in stack
*/
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
	if (top == MAX_SIZE - 1)
	{
		cout << "Error: Stack Overflow" << endl;
		return; 
	}
	top++;
	A[top] = x;
}

void Pop()
{
	if (top == -1)
	{
		cout << "Error: No element to pop" << endl;
		return;
	}
	top--;
}

int Top()
{
	return A[top];
}

void Print()
{
	int i;
	cout << "Stack: ";
	for (i = 0; i <= top; i++)
	{
		cout << A[i] << " ";
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