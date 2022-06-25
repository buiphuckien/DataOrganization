#include <limits.h>
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	//Hàm tạo
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

//Duyệt cây bằng đệ qui để tìm ra node có số dương nhỏ nhất
Node* minPositiveUtil(Node *root)
{
	//Tạo một node có data bằng INT_MAX
	Node *minPos = new Node(INT_MAX);
	//Nếu root bằng NULL thì trả về minPos
	if(root == NULL)
		return minPos;
	//Lấy ra node có số dương nhỏ nhất của các cây con trái và cây con phải
	Node *minPosLeft = minPositiveUtil(root->left);
	Node *minPosRight = minPositiveUtil(root->right);
	//So sánh data của root với data của minPos
	if(root->data > 0 && root->data < minPos->data)
		minPos = root;
	//So sánh data của minPosLeft vói data của minPos
	if(minPosLeft->data > 0 && minPosLeft->data < minPos->data)
		minPos = minPosLeft;
	//So sánh data của minPosRight vói data của minPos
	if(minPosRight->data > 0 && minPosRight->data < minPos->data)
		minPos = minPosRight;
	return minPos;
}

Node* minPositive(Node* root) 
{
	Node* node = minPositiveUtil(root);
	//Nếu cây không có nút mang giá trị dương trả về NULL
	if(node->data == INT_MAX)
		return NULL;
	return node;
}

int main()
{
	Node* root = new Node(-2);
	root->left = new Node(-7);
	root->right = new Node(-5);
	root->left->right = new Node(-56);
	root->left->right->left = new Node(-1);
	root->left->right->right = new Node(-11);
	root->right->right = new Node(-9);
	root->right->right->left = new Node(-4);

	// Function call
	if(minPositive(root) != NULL)
    	cout << "Min positive: " << minPositive(root)->data << endl;
	else
		cout << "NULL." << endl;
	return 0;
}

