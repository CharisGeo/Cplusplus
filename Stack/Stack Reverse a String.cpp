//string reversal using stack
//Time complexity = 0(n)
//Space complexity = 0(n)
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
//
//class Stack
//{
//private:
//	char A[101];
//	int top;
//public:
//	void Push(int x);
//	void Pop();
//	int Top();
//	bool IsEmpty();
//};

void Reverse(char* C, int n)
{
	stack<char> S;
	//loop for push
	for (int i = 0; i < n - 1; i++)
	{
		S.push(C[i]);
	}
	//loop for pop
	for (int i = 0; i < n; i++)
	{
		C[i] = S.top();
		S.pop();
	}
}

int main()
{
	char C[51];
	cout << "Enter a string: ";
	fgets(C, 51, stdin);
	Reverse(C, strlen(C));
	cout << "Output = " << C << endl;
}