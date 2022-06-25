#include "IntBinaryTree.h"
#include <iostream>
using namespace std;

void IntBinaryTree::insertNode(int num)
{
	TreeNode *newNode = NULL;		// Poiter to a new node.

	//Create a new node and store num init
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = NULL;

	// Insert the node.
	insert(root, newNode);
}

void IntBinaryTree::insert(TreeNode* &nodePtr, TreeNode* &newNode)
{
	if (nodePtr == NULL)
		nodePtr = newNode;
	else if(newNode->value == nodePtr->value)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);

}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{ 
	if(nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{ 
	if(nodePtr)
	{
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{ 
	if(nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}