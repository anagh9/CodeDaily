#include<bits/stdc++.h>
#define ll long long
using namespace std;

void FastIo() {
    ios_base::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
    }
};

node* buildTree() {
    int d; cin >> d;
    if (d == -1)
        return nullptr;
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// PreOrder Traversal
void PreOrder(node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

//Inorder Traversal
void Inorder(node* root) {
    if (root == nullptr)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

//PostOrder Traversal
void PostOrder(node*root) {
    if (root == nullptr)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int h = 0;
void heightOfTree(node* root, int depth) {
    if (root == nullptr) {
        h = max(h, depth);
        return;
    }

    heightOfTree(root->left, depth + 1);
    heightOfTree(root->right, depth + 1);
}

int height(node*root) {
    if (root == nullptr)
        return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);

    return max(h1, h2) + 1;
}


void printKthLevel(node*root, int k) {
    if (root == NULL)
        return;

    if (k == 1) {
        cout << root->data << " ";
        return;
    }

    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}

// Level Order Traversal - Recursive O(n^2)
void printAllLevels(node*root) {
    int h = height(root);
    for (int i = 0; i <= h; i++) {
        printKthLevel(root, i);
        cout << endl;
    }
}


void bfs(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node *f = q.front();
        if (f == NULL) {
            // prev level is complete. so print endl
            cout << endl;
            q.pop();
            // prev level has also pushed all its children. So push endl
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << f->data << " ";

            q.pop();

            if (f->left != NULL) {
                q.push(f->left);
            }
            if (f->right != NULL) {
                q.push(f->right);
            }
        }
    }
}

int main() {
    FastIo();
    node* root;
    root->data = 3;
    root->left->data = 23;
    root->right->data = 213;
    root->left->left->data = 43;
    root->left->right->data = 93;


    // node*root = buildTree();
    PreOrder(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;

    heightOfTree(root, 0);// << endl;
    cout << h << endl;
    cout << height(root) << endl;

    printKthLevel(root, 3);
    cout << endl << endl;
    bfs(root);
    cout << endl;

    return 0;
}