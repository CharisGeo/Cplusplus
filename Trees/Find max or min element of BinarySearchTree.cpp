#include <iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* getNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

BstNode* Insert(BstNode* root, int data)
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

bool Search(BstNode* root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return Search(root->left, data);
	}
	else
	{
		return Search(root->right, data);
	}
}

//Iterative Methods
int findMin(BstNode* root)
{
	if (root == NULL)
	{
		cout << "Error: Tree is Empty" << endl;
		return -1;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}

int findMax(BstNode* root)
{
	if (root == NULL)
	{
		cout << "Error: Tree is empty" << endl;
		return -1;
	}
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
}

/*Recurvise methods
int findMin(BstNode* root)
{
	if (head == NULL)
	{
		cout << "Error: Tree is Empty" << endl;
		return -1;
	}
	else if (root->left == NULL)
	{
		return root->data;
	}
	return findMin(root->left);
}

int findMax(BstNode* root)
{
	if (root == NULL)
	{
		cout << "Error: Tree is empty" << endl;
		return -1;
	}
	else if (root->right == NULL)
	{
		return root->data;
	}
	return findMax(root->right);
}
*/
int main()
{
	BstNode* root = NULL;
	root = Insert(root, 10);
	root = Insert(root, 12);
	root = Insert(root, 18);
	int min = findMin(root);
	int max = findMax(root);
	return 0;

}