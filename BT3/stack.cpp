#include <iostream>
#include <stack>
using namespace std;

int main()
{
    unsigned int n;
    cout << "Nhap so nguyen khong am: ";
    cin >> n;
    stack<int> r;
    do
    {
        r.push(n%2);
        n /= 2;
    } while (n>0);
    cout << "Bieu dien nhi phan la: ";
    while(!r.empty())
    {
        cout << r.top();    //In phần tử đầu
        r.pop();            //remove phan tu dau khoi stack
    }
    cout << endl;
}