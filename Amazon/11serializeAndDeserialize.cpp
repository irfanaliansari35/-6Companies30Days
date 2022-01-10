#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void inOrder(Node *root, vector<int> &v)
{
    if (!root)
        return;
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}
vector<int> serialize(Node *root)
{
    //Your code here
    vector<int> v;
    inOrder(root, v);
    return v;
}

//Function to deserialize a list and construct the tree.
Node *buildTree(vector<int> &v, int low, int high)
{
    if (low > high)
        return NULL;
    int mid = (low + high) >> 1;
    Node *root = new Node(v[mid]);
    root->left = buildTree(v, low, mid - 1);
    root->right = buildTree(v, mid + 1, high);
    return root;
}
Node *deSerialize(vector<int> &A)
{
    //Your code here
    int n = A.size();
    return buildTree(A, 0, n - 1);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x : v) cin>>x;

    return 0;
}