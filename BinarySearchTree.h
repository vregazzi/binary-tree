#include <iostream>
#include <stdexcept>
#include <chrono>
#include "BinarySearchTreeNode.h"

template <typename Comparable>
class BinarySearchTree
{
private:
    // make root
    BinarySearchTreeNode<Comparable> *root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(const Comparable &x)
    {
        if (root == nullptr)
        {
            root = new BinarySearchTreeNode(x);
        }
        else
        {
            root->insert(x);
        }
    }

    void inorder_print()
    {
        if (root == nullptr)
        {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
        {
            root->inorder_print();
        }
    }

    void preorder_print()
    {
        if (root == nullptr)
        {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
        {
            root->preorder_print();
        }
    }

    void postorder_print()
    {
        if (root == nullptr)
        {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
        {
            root->postorder_print();
        }
    }
};
