/* Binary tree: Each node can have at most 2 children.
Binary search tree: A binary tree in which for each node, value of all the nodes in left subtree are lesser or equal
and value of all the nodes in the right subtree are greater.
Binary search tree is a recursive structure.
InOrder traversal of a binary search tree should give a sorted list.
*/
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

bool IsSubtreeGreater(Node* root, int value);

bool IsSubtreeLesser(Node* root, int value)
{
	if (root = NULL)
	{
		return true;
	}
	if ((root->data < value)
		&& IsSubtreeGreater(root->left, value)
		&& IsSubtreeGreater(root->right, value))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsSubtreeGreater(Node* root, int value)
{
	if (root == NULL)
	{
		return true;
	}
	if ((root->data > value)
		&& IsSubtreeGreater(root->left, value)
		&& IsSubtreeGreater(root->right, value))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsBinarySearchTree(Node* root)
{
	if (root == NULL)
	{
		return true;
	}
	if (IsSubtreeLesser(root->left, root->data)
		&& IsSubtreeGreater(root->right, root->data)
		&& IsBinarySearchTree(root->left)
		&& IsBinarySearchTree(root->right))
	{
		return true;
	}
	else
	{
		return false;
	}

}

Node* Insert(Node* root, int data)
{
	if (root = NULL)
	{
		root = new Node();
		root->data = data;
		root->left = NULL;
		root->right = NULL;
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

int main()
{
	Node* root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 6);
	root = Insert(root, 9);
	root = Insert(root, 12);
	root = Insert(root, 4);
	root = Insert(root, 34);
	bool result = IsBinarySearchTree(root);
	if (result == true)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}