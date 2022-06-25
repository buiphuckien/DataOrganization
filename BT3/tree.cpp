#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "IntBinaryTree.h"
using namespace std;

int main()
{
    IntBinaryTree tree;
    int x;
    for(int i = 0; i < 10; i++)
    {
        x = rand();
        tree.insertNode(x);
    }
    tree.displayInOrder();

    return 0;
}