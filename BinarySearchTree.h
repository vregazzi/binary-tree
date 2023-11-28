#include <iostream>
#include <stdexcept>
#include <chrono>
#include "BinarySearchTreeNode.h"

template <typename Comparable>
class BinarySearchTree
{
private:
    BinarySearchTreeNode<Comparable> *root;

public:
    BinarySearchTree() : root(nullptr) {}

    /**
     * @brief insert an item into a tree
     *
     * @param x the value to insert in the tree
     */
    void insert(const Comparable &x)
    {
        root = insert_node(root, x);
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

    int height() const
    {
        if (root == nullptr)
        {
            return -1;
        }
        else
        {
            return root->m_height;
        }
    }

    bool contains(const Comparable &x)
    {
        return root->contains(x);
    }

    Comparable find_min()
    {
        if (root == nullptr)
        {
            throw std::logic_error("find_min::Empty Binary Tree");
        }
        else
        {
            return root->find_min();
        }
    }

    Comparable find_max()
    {
        if (root == nullptr)
        {
            throw std::logic_error("find_max::Empty Binary Tree");
        }
        else
        {
            return root->find_max();
        }
    }

    /**
     * @brief print the tree using "depthorder" traversal
     */
    void depthorder_print()
    {
        if (root == nullptr)
        {
            std::cout << "depth_print::Empty Binary Tree" << std::endl;
        }
        else
        {
            // the possible depth values for the tree run from
            // 0 for the root of the tree to the height of the tree
            int tree_height = height();
            std::cout << "Tree Height: " << tree_height << std::endl;
            for (int i = 0; i <= tree_height; ++i)
            {
                // for each possible depth, print just the nodes at that depth
                root->print_depth(0, i);
            }
        }
    }
};
