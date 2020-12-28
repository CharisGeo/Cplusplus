/* Delte a node from BST:
Case 1: No Child
Case 2: 1 Child
Case 3: 2 Children
For case 3 we have to find the MIN VALUE IN RIGHT subtree OR MAX VALUE IN LEFT SUBTREE and copy the value in targeted node.
Then Delete duplicate from right subtree.
Any subtree in a binary search tree is also a binary search tree.
*/
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}

//Function to visit nodes in Inorder
void Inorder(Node* root) {
	if (root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%d ", root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

Node* DeleteNode(Node* root, int data)
{
	if (root == NULL)
	{
		return root;
	}
	else if (data < root->data)
	{
		root->left = DeleteNode(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = DeleteNode(root->right, data);
	}
	else // found node to be deleted
	{
		// Case 1: No child
		if (root->left == NULL && root->right == NULL)
		{
			delete root; // delete address of node to be deleted
			root = NULL;
		}
		// Case 2: One child
		else if (root->left == NULL)
		{
			Node* temp = root; // store address of node we are trying to delete
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		// Case 3: 2 children
		else
		{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = DeleteNode(root->right, temp->data); // correct link in parent i.e set address of deleted left or right child to NULL in parent node
		}
	}
	return root;
}

Node* Insert(Node* root, int data)
{
	if (root == NULL)
	{
		root = new Node();
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return root;
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
	/*Code To Test the logic
	  Creating an example tree
				5
			   / \
			  3   10
			 / \   \
			1   4   11
	*/
	Node* root = NULL;
	root = Insert(root, 5); root = Insert(root, 10);
	root = Insert(root, 3); root = Insert(root, 4);
	root = Insert(root, 1); root = Insert(root, 11);

	// Deleting node with value 5, change this value to test other cases
	root = DeleteNode(root, 5);

	//Print Nodes in Inorder
	cout << "Inorder: ";
	Inorder(root);
	cout << "\n";
}