/* Queue: A list with the restriction that insertion can be performed at one end (Rear)
and deletion can be performed at other end (Front).
First In - First Out
Operations take constant time 0(1) / do not depend on number of elements
Applications:
1) Printer Queue
2) Process scheduling
3) Simulating wait
When queue if full array is circular index of rear becomes 0
*/
#include <iostream>
using namespace std;

int A[5];
int n = sizeof(A) / sizeof(A[0]);
int front = -1;
int rear = -1;

bool isEmpty()
{
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

void Enqueue(int x)
{
	if ((rear + 1) % n == front)
		return;
	else if (isEmpty())
	{
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear + 1) % n;
	}
	A[rear] = x;
}

void Dequeue()
{
	if (isEmpty())
	{
		return;
	}
	else if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front + 1) % n;
	}
}

void output()
{
	cout << A[front] << endl;;
}

int main()
{
	isEmpty();
	Enqueue(2);
	Enqueue(4);
	output();
	Enqueue(13);
	Dequeue();
	Enqueue(7);
	output();
	isEmpty();
}