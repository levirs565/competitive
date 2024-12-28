#include <iostream>

using namespace std;

struct Node
{
    int p;
    int v;
    Node *left = nullptr, *right = nullptr;
};

void split(Node *root, int v, Node *&left, Node *&right)
{
    if (!root)
    {
        left = right = nullptr;
    }
    else if (v <= root->v)
    {
        split(root->left, v, left, root->left);
        right = root;
    }
    else
    {
        split(root->right, v, root->right, right);
        left = root;
    }
}

Node *merge(Node *left, Node *right)
{
    if (left == nullptr)
        return right;
    else if (right == nullptr)
        return left;
    else if (left->p <= right->p)
    {
        right->left = merge(left, right->left);
        return right;
    }
    else
    {
        left->right = merge(left->right, right);
        return left;
    }
}

Node* insert(Node* root, Node* node) {
    if (!root)
        return node;
    else if (node->p > root->p) {
        split(root, node->v, node->left, node->right);
        return node;
    } else {
        if (node->v < root->v) {
            root->left = insert(root->left, node);
        } else {
            root->right = insert(root->right, node);
        }
        return root;
    }
}

Node *erase(Node* root, int v) {
    if (v < root->v) {
        root->left = erase(root->left, v);
        return root;
    } else if (v > root->v) {
        root->right = erase(root->right, v);
        return root;
    } else {
        Node* res = merge(root->left, root->right);
        delete root;
        return res;
    }
}

void inorder(Node *node) {
    if (!node) return;

    inorder(node->left);
    cout << node->v << endl;
    inorder(node->right);
}

void preorder(Node *node, const std::string& tab) {
    if (!node) return;

    cout << tab << node->v << "," << node->p << endl;
    preorder(node->left, tab + "    ");
    preorder(node->right, tab + "    ");
}

int main() {
    Node* root = nullptr;

    for (int i = 0; i < 10; i++) {
        Node *node = new Node();
        node->p = rand();
        node->v = i;
        root = insert(root, node);
    }

    preorder(root, "");
}