using namespace std;

#include "BinarySearchTree.h"

int simple_insertion()
{
    BinarySearchTree<int> tree;
    cout << "Simple insertion testing" << endl;
    tree.insert(17);
    tree.insert(25);
    tree.insert(4);
    tree.insert(88);
    tree.insert(1);
    tree.insert(6);
    tree.insert(5);

    cout << "contains 17: " << endl;
    cout << tree.contains(17) << endl; // should be 1
    cout << endl;

    cout << "contains 25: " << endl;
    cout << tree.contains(25) << endl; // should be 1
    cout << endl;

    cout << "contains 90: " << endl;
    cout << tree.contains(90) << endl; // should be 0
    cout << endl;

    cout << "contains 0: " << endl;
    cout << tree.contains(0) << endl; // should be 0
    cout << endl;

    cout << "find_min: " << endl;
    cout << tree.find_min() << endl; // should be 1
    cout << endl;

    cout << "find_max: " << endl;
    cout << tree.find_max() << endl; // should be 88
    cout << endl;

    cout << "inorder_print" << endl;
    tree.inorder_print();
    cout << endl;

    cout << "preorder_print" << endl;
    tree.preorder_print();
    cout << endl;

    cout << "postorder_print" << endl;
    tree.postorder_print();
    cout << endl;

    cout << "depthorder_print" << endl;
    tree.depthorder_print();
    cout << endl;

    return 0;
}

int main()
{
    simple_insertion();
}