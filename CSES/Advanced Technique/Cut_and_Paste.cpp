#include <iostream>
#include <array>
#include <string>

using namespace std;
using i64 = int64_t;

struct Node
{
    int p;
    char v;
    int cnt;
    Node *left, *right;
};

void update_cnt(Node *node)
{
    if (node != nullptr)
    {
        node->cnt = 1;
        if (node->left)
            node->cnt += node->left->cnt;
        if (node->right)
            node->cnt += node->right->cnt;
    }
}

// i >= idx, masuk right
// idx <= i
void split(Node *root, int idx, Node *&left, Node *&right)
{
    if (root == nullptr)
    {
        left = right = nullptr;
        return;
    }
    int i = 1 + (root->left ? root->left->cnt : 0);
    if (idx > i)
    {
        split(root->right, idx - i, root->right, right);
        left = root;
    }
    else
    {
        split(root->left, idx, left, root->left);
        right = root;
    }
    update_cnt(root);
}

Node *merge(Node *left, Node *right)
{
    if (left == nullptr)
    {
        update_cnt(left);
        return right;
    }
    else if (right == nullptr)
    {
        update_cnt(right);
        return left;
    }
    else if (left->p > right->p)
    {
        left->right = merge(left->right, right);
        update_cnt(left);
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        update_cnt(right);
        return right;
    }
}

void preorder(Node *root, const string &tab)
{
    if (root == nullptr)
        return;

    cout << tab << root->v << "," << root->p << "," << root->cnt << endl;
    preorder(root->left, tab + "    ");
    preorder(root->right, tab + "    ");
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->v << "," << root->p << "," << root->cnt << endl;
    inorder(root->right);
}

void inorderresult(Node* root) {
    if (root == nullptr) return;
    inorderresult(root->left);
    cout << root->v;
    inorderresult(root->right);
}

void solution()
{
    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    Node *root = nullptr;
    for (char ch : str)
    {
        Node *node = new Node();
        node->cnt = 1;
        node->p = rand();
        node->v = ch;
        root = merge(root, node);
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        Node *p = nullptr, *q = nullptr, *r = nullptr;
        split(root, a, p, q);
        split(q, b - a + 2, q, r);

        // cout << m << endl;
        // cout << "p " << a << endl;
        // inorder(p);
        // cout << "q" << b << endl;
        // inorder(q);
        // cout << "r" << endl;
        // inorder(r);
        
        // cout << "root" << endl;
        root = merge(merge(p, r), q);
        // inorder(root);
    }

    inorderresult(root);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}