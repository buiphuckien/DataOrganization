// Recursive C++ program to reverse
// a linked list
#include <iostream>
using namespace std;

/* Link list NODE */
struct NODE {
	int data;
	struct NODE* next;
	NODE(int data)
	{
		this->data = data;
		next = NULL;
	}
};

NODE* reverseUtil(NODE* &head, NODE* node)
{
	//Nếu node bằng NULL thì return NULL
	if (node == NULL)
		return NULL;
	//Nếu node là node cuối của danh sách return node
	if (node->next == NULL) {
		head = node;
		return node;
	}
	//Đệ qui - đảo ngược các phần tử của danh sách từ node->next trở đi.
	//Trả về node cuối danh sách sau khi đảo. Gọi đó là node1.
	NODE* node1 = reverseUtil(head, node->next);
	//Điều chỉnh liên kết của node1 và node.
	node1->next = node;
	node->next = NULL;
	return node;
}
/* reverse2 */
void reverse2(NODE* &head)
{
	//Gọi hàm reverseUtil với hai tham số truyền vào là head và head
    reverseUtil(head, head);
}

struct LinkedList {
	NODE* head;
	LinkedList()
	{
		head = NULL;
	}

	/* Function to reverse the linked list */
	NODE* reverse(NODE* node)
	{
		if (node == NULL)
			return NULL;
		if (node->next == NULL) {
			head = node;
			return node;
		}
		NODE* node1 = reverse(node->next);
		node->next = node;
		node->next = NULL;
		return node;
	}

	/* reverse2 */
    void reverse2(NODE* &NODE)
    {
        reverse(NODE);
    }


	/* Function to print linked list */
	void print()
	{
		struct NODE* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		NODE* temp = new NODE(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	reverse2(ll.head);

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}
