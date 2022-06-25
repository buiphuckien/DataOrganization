#include <iostream>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

void insert(NODE *&head, int x)
{
    NODE *node = new NODE;
    node->data = x;

    NODE *p1 = NULL;
    NODE *p2 = head;
    while (p2 != NULL && p2->data <= x) 
    {
        p1 = p2;
        p2 = p2->next;
    }
    node->next = p2;
    if(p1 == NULL)
        head = node;
    else
        p1->next = node;
}

void print(NODE *head)
{
    for(NODE *p = head; p != NULL; p = p->next)
        cout << p->data << " ";
}

//Tinh chieu dai danh sach lien ket
int length(NODE *head)
{
    if(head == NULL)
        return 0;
    return 1 + length(head->next);
}

//Tinh chieu dai Chuoi
int lengthOfString(const char *str)
{
    if(*str == '\0')
        return 0;
    return 1 + lengthOfString(str + 1);
}

NODE* linearSearch(NODE *head, int key)
{
    if(head->data == key)
        return head;
    return linearSearch(head->next, key);
}

int main()
{
    NODE *head = NULL;
    int x;
    cout << "Nhap cac so nguyen (cho den o thi dung):\n";
    cin >> x;
    while(x != 0)
    {
        insert(head, x);
        cin >> x;
    }
    cout << "Danh sach da nhap la: ";
    print(head);
}