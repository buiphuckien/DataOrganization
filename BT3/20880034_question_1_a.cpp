// Iterative C++ program to reverse
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

void reverse1(NODE* &head)
{
	//Khởi tạo các NODE con trỏ current, prev, và next
	NODE* current = head;
	NODE *prev = NULL, *next = NULL;

	while (current != NULL) 
	{
		// Lưu lại NODE next
		next = current->next;

		// Đảo pointer của con trỏ hiện tại
		current->next = prev;

		// Di chuyển các con trỏ sang vị trí tiếp theo
		prev = current;
		current = next;
	}

	//Khi current = NULL, gán lại head
	head = prev;
}

struct LinkedList {
	NODE* head;
	LinkedList() { head = NULL; }

	/* Function to reverse the linked list */
	void reverse1()
	{
		// Initialize current, previous and
		// next pointers
		NODE* current = head;
		NODE *prev = NULL, *next = NULL;

		while (current != NULL) {
			// Store next
			next = current->next;

			// Reverse current NODE's pointer
			current->next = prev;

			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		head = prev;
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

/* Driver code*/
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

	reverse1(ll.head);

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}
