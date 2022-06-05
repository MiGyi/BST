#include <iostream>

using namespace std;

#include "BST.h"

int main()
{
    int a[] = {120, 70, 200, 35, 82, 12, 57, 75, 110, 3, 26, 71, 80, 96, 115, 32, 111
        , 150, 128, 372, 563, 496, 612};
    BST tree;
    for (int i = 0; i < 23; i++) tree.AddNode(a[i]);
    //tree.Traverse();
    int x;
    cin >> x;
    Node *res = tree.FindClosest(x);
    cout << res->val;
    return 0;
}
