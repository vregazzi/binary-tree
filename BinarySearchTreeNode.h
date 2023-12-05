template <typename Comparable>

class BinarySearchTreeNode
{
public:
    BinarySearchTreeNode(
        Comparable value,
        BinarySearchTreeNode *left,
        BinarySearchTreeNode *right)
        : m_value(value), m_left(left), m_right(right) {}
    Comparable m_value;
    BinarySearchTreeNode *m_left;
    BinarySearchTreeNode *m_right;
    int m_height = 0;

    void preorder_print()
    {
        std::cout << m_value << std::endl;
        if (m_left != nullptr)
        {
            m_left->preorder_print();
        }
        if (m_right != nullptr)
        {
            m_right->preorder_print();
        }
    }

    void postorder_print()
    {
        if (m_left != nullptr)
        {
            m_left->postorder_print();
        }
        if (m_right != nullptr)
        {
            m_right->postorder_print();
        }
        std::cout << m_value << std::endl;
    }

    void inorder_print()
    {
        if (m_left != nullptr)
        {
            m_left->inorder_print();
        }
        std::cout << m_value << std::endl;
        if (m_right != nullptr)
        {
            m_right->inorder_print();
        }
    }

    int left_child_height()
    {
        int height = -1;
        if (m_left != nullptr)
        {
            height = m_left->m_height;
        }

        return height;
    }

    int right_child_height()
    {
        int height = -1;
        if (m_right != nullptr)
        {
            height = m_right->m_height;
        }

        return height;
    }

    void update_height()
    {
        m_height = std::max(left_child_height(), right_child_height()) + 1;
    }

    const Comparable &find_max() const
    {
        if (m_right == nullptr)
        {
            return m_value;
        }
        else
        {
            return m_right->find_max();
        }
    }

    const Comparable &find_min() const
    {
        if (m_left == nullptr)
        {
            return m_value;
        }
        else
        {
            return m_left->find_min();
        }
    }

    /**
     * @brief return an indication of whether or not the tree rooted
     * at this node contains the specified element
     *
     * @param x the element to determine whether or not is it is in the tree
     * rooted at this node
     *
     * @returns true if x is found in the tree, false otherwise
     */
    bool contains(const Comparable &x) const
    {
        if (x < m_value)
        {
            if (m_left != nullptr)
            {
                return m_left->contains(x);
            }
            else
            {
                return false;
            }
        }
        else if (x > m_value)
        {
            if (m_right != nullptr)
            {
                return m_right->contains(x);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }

    /**
     * @brief print the elements of the subtree rooted at the current node by
     * depth
     *
     * print out all the nodes at depth print_depth; followed by all the nodes
     * at print_depth + 1; followed by all the nodes at print_depth + 2; etc.
     *
     * @param current_depth the depth of the tree we are currently "at"
     * @param print_depth the depth of the nodes that should be printed
     */
    void print_depth(int current_depth, int print_depth)
    {
        if (current_depth > print_depth)
        {
            // if we are deeper in the tree than the print_depth,
            // then we are done.
            return;
        }
        else if (current_depth == print_depth)
        {
            // if we are at the print_depth, then print the node value
            std::cout << "depth: " << current_depth << " value: " << m_value
                      << " height: " << m_height << std::endl;
        }
        else
        {
            // if we are not yet deep enough in the tree to print,
            // go one level deeper wherever we can
            if (m_left != nullptr)
            {
                m_left->print_depth(current_depth + 1, print_depth);
            }
            if (m_right != nullptr)
            {
                m_right->print_depth(current_depth + 1, print_depth);
            }
        }
    }
};

/**
 * @brief determine the height of the given BinarySearchTreeNode.
 *
 * @returns the height of the given BinarySearchTreeNode
 */
template <typename Comparable>
int height(BinarySearchTreeNode<Comparable> *node)
{
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        return node->m_height;
    }
}

/**
 * @brief determine the balance factor for the specified BinarySearchTreeNode
 *
 * @returns positive value means left child is taller than the right child;
 * negative value means right child is taller than left child; magnitude of
 * value is how much one child is taller than the other; 0 value means
 * children have the same height
 */
template <typename Comparable>
int calculate_balance(BinarySearchTreeNode<Comparable> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return height(node->m_left) - height(node->m_right);
    }
}

/**
 * @brief insert a node with the specified value (x) in the subtree rooted at the
 * specified node (node)
 *
 * @param node the node which is the root of the subtree into which to insert a
 * new node
 * @param x the value to be inserted
 *
 * @returns the root of the newly inserted subtree.
 */
template <typename Comparable>
BinarySearchTreeNode<Comparable> *insert_node(
    BinarySearchTreeNode<Comparable> *node, const Comparable &value_to_insert)
{
    if (node == nullptr)
    {
        return new BinarySearchTreeNode<Comparable>(value_to_insert, nullptr, nullptr);
    }
    if (value_to_insert < node->m_value)
    {
        // insert into the left subtree
        node->m_left = insert_node(node->m_left, value_to_insert);
    }
    else if (node->m_value < value_to_insert)
    {
        // insert into the right subtree
        node->m_right = insert_node(node->m_right, value_to_insert);
    }
    else
    {
        // x must be equal to the current node's value
        // no need to create a new node, insert it, or balance anything
        return node;
    }
    node->update_height();
    int balance = calculate_balance(node);
    if (balance > 1)
    {
        if (value_to_insert < node->m_left->m_value)
        {
            node = right_rotate(node);
        }
        else
        {
            node->m_left = left_rotate(node->m_left);
            node = right_rotate(node);
        }
    }
    else if (balance < -1)
    {
        if (value_to_insert > node->m_right->m_value)
        {
            node = left_rotate(node);
        }
        else
        {
            node->m_right = right_rotate(node->m_right);
            node = left_rotate(node);
        }
    }
    return node;
}

template <typename Comparable>
BinarySearchTreeNode<Comparable> *left_rotate(
    BinarySearchTreeNode<Comparable> *node)
{
    BinarySearchTreeNode<Comparable> *new_root = node->m_right;
    node->m_right = new_root->m_left;
    new_root->m_left = node;
    node->update_height();
    new_root->update_height();
    return new_root;
}

template <typename Comparable>
BinarySearchTreeNode<Comparable> *right_rotate(
    BinarySearchTreeNode<Comparable> *node)
{
    BinarySearchTreeNode<Comparable> *new_root = node->m_left;
    node->m_left = new_root->m_right;
    new_root->m_right = node;
    node->update_height();
    new_root->update_height();
    return new_root;
}
