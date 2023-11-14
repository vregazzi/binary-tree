using namespace std;

#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> tree;
    tree.insert(17);
    tree.insert(25);
    tree.insert(4);
    tree.insert(88);
    tree.insert(1);
    tree.insert(6);
    tree.insert(5);

    cout << "inorder_print" << endl;
    tree.inorder_print();
    cout << endl;

    cout << "preorder_print" << endl;
    tree.preorder_print();
    cout << endl;

    cout << "postorder_print" << endl;
    tree.postorder_print();

    return 0;
}