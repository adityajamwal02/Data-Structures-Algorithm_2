#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
     int l, r, max;
     Node* left; Node* right;
 Node(int lVal, int rVal) { l = lVal; r = rVal; max = rVal; left = right = NULL; }
};
Node* newNode(int l, int r)
{ Node* node = new Node(l, r);
 return node;}
Node* insert(Node* root, int l, int r)
{ if (root == NULL)
 { return newNode(l, r);}
 if (l < root->l) { root->left = insert(root->left, l , r);}
 else if (l > root->l) { root->right = insert(root->right, l, r);}
 else { if (r < root->r) {root->left = insert(root->left, l, r);}
 else { root->right = insert(root->right, l, r);} }
 if (root->max < r) {
 root->max = r;
 }
 return root;
}
Node* deleteInterval(Node* root, int l, int r) {
 if (root == NULL)
 {
 return NULL;
 }

 if (l < root->l)
 {
 root->left = deleteInterval(root->left, l, r);
 } else if (l > root->l)
 {
 root->right = deleteInterval(root->right, l, r);
 }
 else
 {
 if (r < root->r) {
 root->left = deleteInterval(root->left, l, r);
 } else if (r > root->r) {
 root->right = deleteInterval(root->right, l, r);
 } else {
 if (root->left == NULL)
 return root->right;
 else if (root->right == NULL)
 return root->left;
 Node* curr = root->right;
 while (curr->left != NULL) {
 curr = curr->left;
 }
 root->l = curr->l;
 root->r = curr->r;

 root->right = deleteInterval(root->right, root->l, root->r);
 }
 }
 return root;
}
int main() {
 Node *root = NULL;
 root = insert(root, 23, 58);
 root = insert(root, 32, 36);
 root = insert(root, 58, 89);
 root = insert(root, 12, 78);
 root = insert(root, 56, 85);
 root = insert(root, 79, 98);
 root = insert(root, 45, 72);
 root = insert(root, 39, 69);
 root = insert(root, 8, 24);
 root = insert(root, 2, 9);
 root = insert(root, 19, 29);
 root = insert(root, 21, 64);
 root = deleteInterval(root, 12, 78);
 root = deleteInterval(root,45, 72);
 return 0;
}
