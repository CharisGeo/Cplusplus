/* Check if given string is Palindrome:
A palindrome is a word, phrase, number, or other sequence of characters which reads the same backwards and forwards. Can you determine if a given string, s, is a palindrome?

To solve this challenge, we must first take each character in s, enqueue it in a queue, and also push that same character onto a stack. 
Once that's done, we must dequeue the first character from the queue and pop the top character off the stack, then compare the two characters to see if they are the same;
as long as the characters match, we continue dequeueing, popping, and comparing each character until our containers are empty (a non-match means isn't a palindrome)
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
private:
	stack<char> S;
	queue<char> Q;
public:
	void pushCharacter(char ch) { S.push(ch); };
	void enqueueCharacter(char ch) { Q.push(ch); };
	char popCharacter() { char temp = S.top(); S.pop(); return temp; };
	char dequeueCharacter() { char temp = Q.front(); Q.pop(); return temp; };
};

int main()
{
	string mystr;
	cout << "Enter the string to check: " << endl;
	getline(cin, mystr);

	int n = mystr.length();
	Solution obj;
	bool isPalindrome = true;

	for (int i = 0; i < n; i++)
	{
		obj.pushCharacter(mystr[i]);
		obj.enqueueCharacter(mystr[i]);
	}

	for (int i = 0; i < n / 2; i++)
	{
		if (obj.dequeueCharacter() != obj.popCharacter())
		{
			isPalindrome = false;
			break;
		}
	}

	if (isPalindrome == true)
	{
		cout << "String is palindrome!" << endl;
	}
	else
	{
		cout << "String is not a palindrome!" << endl;
	}

	return 0;
}