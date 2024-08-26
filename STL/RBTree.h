#ifndef RBTREE_H
#define RBTREE_H

enum Color { RED, BLACK };

template <typename Key, typename Value> 
class RedBlackTree {
    class Node {
    public:
        Key key;
        Value value;
        Color color;
        Node *left;
        Node *right;
        Node *parent;

        Node(const Key &k, const Value &v, Color c, Node *p = nullptr) : 
            key(k), value(v), color(c), left(nullptr), right(nullptr), parent(p) {}

        Node() : key(Key()), value(Value()), color(Color::BLACK), left(nullptr), right(nullptr), parent(nullptr) {}
    };
private:
    Node *root;
    size_t size;
    Node *Nil;

    // 查询节点
    Node *lookUp(Key &key) {
        Node *cur = root;
        while (cur) {
            if (key < cur->key)
                cur = cur->left;
            else if (key > cur->key)
                cur = cur->right;
            else   
                return cur;
        }
        return cur;
    }

    // 右旋
    void rightRotate(Node *node) {
        // 获取左节点，作为旋转节点
        Node *pivot = node->left;
        // 将pivot的右节点挂到node的左节点
        node->left = pivot->right;
        // 如果pivot的右节点不为空，将其父节点指向node
        if (pivot->right)
            pivot->right->parent = node;

        // 将pivot上升到node的位置
        pivot->parent = node->parent;
        if (!node->parent)
            root = pivot;
        else if (node == node->parent->left)
            node->parent->left = pivot;
        else
            node->parent->right = pivot;
        
        // 将node挂到pivot的右节点
        pivot->right = node;
        node->parent = pivot;
    }

    // 左旋
    void leftRotate(Node *node) {
        Node *pivot = node->right;
        node->right = pivot->left;
        if (pivot->left)
            pivot->left->parent = node;

        pivot->parent = node->parent;
        if (!node->parent)
            root = pivot;
        else if (node == node->parent->left)
            node->parent->left = pivot;
        else
            node->parent->right = pivot;

        pivot->left = node;
        node->parent = pivot;
    }

    // 插入修复
    void insertFixup(Node *target) {
        // 父节点是红色时，需要修复
        while (target->parent && target->parent->color == Color::RED) {
            // 父节点是祖父节点的左节点
            if (target->parent == target->parent->parent->left) {
                Node *uncle = tarhet->parent->parent->right;
                // 叔叔节点是红色，只需要重新着色
                if (uncle && uncle->color == Color::RED) {
                    target->parent->color = Color::BLACK;
                    uncle->color - Coloc::BLACK;
                    uncle->parent->color = Color::RED;
                    target = target->parent->parent;
                }
                else {
                    // 如果target是父节点的右节点，需要左旋后再着色右旋
                    if (target == target->parent->right) {
                        target = target->parent;
                        leftRotate(target);
                    }
                    // 着色，右旋
                    target->parent->color = Color::BLACK;
                    target->parent->parent->color = Color::RED;
                    rightRotate(target->parent->parent);
                }
            }
            // 父节点是祖父节点的右节点
            else {
                Node *uncle = target->parent->parent->left;
                if (uncle && uncle->color == Color::RED) {
                    target->parent->color = Color::BLACK;
                    uncle->color = Color::BLACK;
                    uncle->parent->color = Color::RED;
                    target = target->parent->parent;
                }
                else {
                    if (target == target->parent->left) {
                        target = target->parent;
                        rightRotate(target);
                    }
                    target->parent->color = Color::BLACK;
                    target->parent->parent->color = Color::RED;
                    leftRotate(target->parent->parent);
                }
            } 
        }
        // 根节点着色为黑色
        root->color = Color::BLACK;
    }

    // 插入节点
    void insertNode(const Key &key, const Value &value) {
        Node *newNode = new Node(key, value, Color::RED);
        Node *parent = nullptr;
        Node *cur = root;

        while (cur) {
            parent = cur;
            if (key < cur->key)
                cur = cur->left;
            else if (key > cur->key)
                cur = cur->right;
            else {
                cur->value = value;
                return;
            }
        }

        ++size;
        newNode->parent = parent;
        if (!parent)
            root = newNode;
        else if (key < parent->key)
            parent->left = newNode;
        else
            parent->right = newNode;

        insertFixup(newNode);
    }

    // 中序遍历
    void inorderTraversal(Node *node) const {
        if (!node)
            return;
        inorderTraversal(node->left);
        std::cout << node->key << " ";
        std::cout << node->value << std::endl;
        inorderTraversal(node->right);
    }

    // 辅助函数，用新节点替换旧节点
    void replaceNode(Node *targetNode, Node *newNode) {
        if (!targetNode->parent)
            root = newNode;
        else if (targetNode == targetNode->parent->left)
            targetNode->parent->left = newNode;
        else
            targetNode->parent->right = newNode;

        if (newNode)
            newNode->parent = targetNode->parent;

        delete targetNode;
    }

    // 辅助函数，寻找以node为根的最小节点
    Node *findMinimumNode(Node *node) {
        while (node->left)
            node = node->left;
        return node;
    }

    // 删除修复
    void removeFixup(Node *node) {
        // 如果是唯一节点，不需要修复
        if (node == Nil && node->parent == nullptr)
            return;
        // 如果删除节点是红色，不需要修复
        if (node && node->color == Color::RED)
            return;

        while (node != root) {
            // 如果节点是其父节点的左子节点
            if (node == node->parent->left) {
                Node *sibling = node->parent->right;

                // 1: 兄弟节点是红色
                if (getColor(sibling) == Color::RED) {
                    setColor(sibling, Color::BLACK);
                    setColor(node->parent, Color::RED);
                    leftRotate(node->parent);
                }
            }
        }
    }
};

#endif