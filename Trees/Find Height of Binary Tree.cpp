/* Height of Tree: Number of edges in longest path from root to a leaf node.
Leaf node: Node with no children.
Height of tree = Height of root
Height of tree with 1 node = 0
Depth of a node: Number of edges in path from root to that node
Heigth = max depth
Time complexity of find height algorithm is O(n)
*/
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

int findHeight(Node* root)
{
	if (root == NULL)
	{
		return -1;
	}
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

Node* getNewNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, int data)
{
	if (root == NULL)
	{
		root = getNewNode(data);
	}
	else if (data <= root->data)
	{
		root = Insert(root->left, data);
	}
	else
	{
		root = Insert(root->right, data);
	}
	return root;
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 10);
	root = Insert(root, 15);
	root = Insert(root, 8);
	root = Insert(root, 25);
	int height = findHeight(root);
	cout << "Height is: " << height << endl;
}