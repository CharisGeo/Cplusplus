/* Depth first search algorithm
Preorder:
<root><left><right>
InOrder:
<left><root><right>
PostOrder:
<left><right><root>
Because of recursion we are growing the function call stack (memory).
Extra space used is proportional to the height of the tree.
Space complexity: O(h) where h is the height of the tree.
Inorder traversal of a binary search tree returns elements in a sorted manner.
*/
#include <iostream>
using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;
};

Node* getNewNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, char data)
{
	if (root == NULL)
	{
		root = getNewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

void Preorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data;
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Inorder(root->left);
	cout << root->data;
	Inorder(root->right);
}

void Postorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data;
}

int main()
{
	/*Code To Test the logic
	Creating an example tree
			M
		   / \
		  B   Q
		 / \   \
		A   C   Z
	*/
	Node* root = NULL;
	root = Insert(root, 'M'); root = Insert(root, 'B');
	root = Insert(root, 'Q'); root = Insert(root, 'Z');
	root = Insert(root, 'A'); root = Insert(root, 'C');
	//Print Nodes in Preorder. 
	cout << "Preorder: ";
	Preorder(root);
	cout << "\n";
	//Print Nodes in Inorder
	cout << "Inorder: ";
	Inorder(root);
	cout << "\n";
	//Print Nodes in Postorder
	cout << "Postorder: ";
	Postorder(root);
	cout << "\n";
}