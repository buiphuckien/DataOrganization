#include <iostream>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

struct LIST
{
    NODE *first;
    NODE *last;
};

void init(LIST &list){
    list.first = list.last = NULL;
}

void addlast(LIST &list, int x)
{
    NODE *node = new NODE;
    node->data = x;
    node->next = NULL;
    if(list.last == NULL)
    {
        list.first = list.last = node;
    }
    else
    {
        list.last->next = node;
        list.last = node;
    }
}

void print(LIST list)
{
    for(NODE *p = list.first; p != NULL; p = p->next)
        cout << p->data << " ";
}

int main()
{
    LIST list;
    init(list);
    int x;
    cout << "Nhap cac so nguyen (cho den o thi dung):\n";
    cin >> x;
    while(x != 0)
    {
        addlast(list, x);
        cin >> x;
    }
    cout << "Danh sach da nhap la: ";
    print(list);
}