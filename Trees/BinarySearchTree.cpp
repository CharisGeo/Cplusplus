/* Tree:
N Nodes - N-1 Links
Applications:
1. Storing hierarchical data e.g file system.
2.Organize data for quick search, insertion aand deletion e.g Binary Search Trees
3.Trie - > dictionary
4. Network routing algorithm
Binary Tree: Each node in the tree can have a max of 2 children
Binary Search Tree is an efficient structure for storing ordered data
Binary search - O(logn)
Keep binary search tree balanced in order for search, insertion and deletion operations to all be O(logn)
A tree is balanced if for all nodes, the difference between the heightsof left and right subtress is not greater than 1
Binary Search Tree: A binary tree in which for EACH NODE, the value of all the nodes in the left subtree are lesser or equal
and the values of all the nodes in the right subtree are graeter.
*/
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
	return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root = NULL)
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

int main()
{
	BstNode* root = nullptr;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	int number;
	cout << "Enter number to be searched: " << endl;
	cin >> number;
	if (Search(root, number) == true)
	{
		cout << "Found" << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}
	return 0;
}