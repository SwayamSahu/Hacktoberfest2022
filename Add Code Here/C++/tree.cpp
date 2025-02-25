<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void inorder(Node *root) // time comp O(n) aux space O(h) , n is the number of node and h is the height of the tree
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << (root->key) << " ";
        inorder(root->right);
    }
}
void postorder(Node *root) // time comp O(n) aux space O(h) , n is the number of node and h is the height of the tree
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << (root->key) << " ";
    }
}
void preorder(Node *root) // time comp O(n) aux space O(h) , n is the number of node and h is the height of the tree
{
    if (root != NULL)
    {
        cout << (root->key) << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void iterativeInorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << (curr->key) << " ";
        curr = curr->right;
    }
}
void OptimizediterativePreorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            cout << curr->key << " ";
            if (curr->right != NULL)
                s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}
void iterativePostorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    Node *prev = NULL;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        if (curr->right == NULL || curr->right == prev)
        {
            cout << (curr->key) << " ";
            s.pop();
            prev = curr;
            curr = NULL;
        }
        else
            curr = curr->right;
    }
}
int size(Node *root) // time comp O(n) aux sapce O(h)
{
    if (root == NULL)
    {
        return 0;
    }
    return (1 + size(root->left) + size(root->right));
}
int getMax(Node *root) // time comp O(n) aux sapce O(h)
{

    if (root == NULL)
    {
        return -1;
    }

    return (max(root->key, max(getMax(root->left), getMax(root->right))));
}
int height(Node *root) // time comp O(n) aux sapce O(h)
{
    if (root == NULL)
    {
        return 0;
    }
    return (1 + max(height(root->left), height(root->right)));
=======
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

};
int search(int inorder[], int start, int end, int curr)
{
    for(int i = start; i<=end; i++)
    {
        if(inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if(start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    Node* node = new Node();
    node->data=curr;
    if(start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder,inorder,start,pos-1);
    node->right = buildTree(preorder,inorder,pos+1,end);
    return node;
}

void inorderprint(Node* root)
{
    Node* temp = root;
    if(temp == NULL)
    {
        return;
    }
    inorderprint(temp->left);
    cout<<temp->data<<" ";
    inorderprint(temp->right);
>>>>>>> 94a4bca07f2b0d8e32946fbb00433c2b9ae95e43
}

int main()
{
<<<<<<< HEAD
    // an empty tree is represented by null;
    // Node *root = NULL;

    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->right->right = new Node(60);
    cout << "Size of the tree : " << size(root) << endl;
    cout << "Max value in the tree  : " << getMax(root) << endl;
    cout << "Height of the tree " << height(root) << endl;
    cout << "Inorder traversal : ";
    inorder(root);

    cout << "\nPreorder traversal : ";
    preorder(root);

    cout << "\nPostorder traversal : ";
    postorder(root);

    cout << "\nIterative Inorder traversal : ";
    iterativeInorder(root);

    cout << "\nOptimized Iterative Preorder traversal : ";
    OptimizediterativePreorder(root);

    cout << "\nIterative Postorder traversal : ";
    iterativePostorder(root);
}
=======
    // int n;
    // cin>>n;
    int preorder[] = {1,2,4,3,5};
    // for(int i=0; i<n; i++)
    // {
    //     cin>>preorder[i];
    // }
    int inorder[] = {4,2,1,5,3};
    // for(int i=0; i<n; i++)
    // {
    //     cin>>inorder[i];
    // }

    Node* root = buildTree(preorder,inorder,0,4);
    inorderprint(root);

}

>>>>>>> 94a4bca07f2b0d8e32946fbb00433c2b9ae95e43
