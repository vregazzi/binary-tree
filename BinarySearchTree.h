#include <iostream>
#include <stdexcept>
#include <chrono>

template <typename Comparable>
class BinarySearchTree
{
private:
    class BinarySearchTreeNode
    {
    public:
        BinarySearchTreeNode(Comparable value) : value(value), left(nullptr), right(nullptr) {}
        Comparable value;
        BinarySearchTreeNode *left;
        BinarySearchTreeNode *right;

        void insert(const Comparable &x)
        {
            if (x < value)
            {
                if (left == nullptr)
                {
                    left = new BinarySearchTreeNode(x);
                    return;
                }
                else
                {
                    left->insert(x);
                    return;
                }
            }
            else if (x > value)
            {
                if (right == nullptr)
                {
                    right = new BinarySearchTreeNode(x);
                    return;
                }
                else
                {
                    right->insert(x);
                    return;
                }
            }
            else
            {
                throw std::logic_error("Duplicate value in tree");
            }
        }

        void preorder_print()
        {
            std::cout << value << std::endl;
            if (left != nullptr)
            {
                left->preorder_print();
            }
            if (right != nullptr)
            {
                right->preorder_print();
            }
        }

        void postorder_print()
        {
            if (left != nullptr)
            {
                left->postorder_print();
            }
            if (right != nullptr)
            {
                right->postorder_print();
            }
            std::cout << value << std::endl;
        }

        void inorder_print()
        {
            if (left != nullptr)
            {
                left->inorder_print();
            }
            std::cout << value << std::endl;
            if (right != nullptr)
            {
                right->inorder_print();
            }
        }
    };
    BinarySearchTreeNode *root;

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
