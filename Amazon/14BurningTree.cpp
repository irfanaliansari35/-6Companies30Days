#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

int findTime(Node* root,unordered_map<Node*,Node*>&mp)
    {
        unordered_map<Node*,bool>vis;
        queue<Node*>q;
        int time = 0;
        q.push(root);
       
        while(!q.empty())
        {
            int size = q.size();
            int f=0;
            while(size--)
            {
                Node* currRoot = q.front();
                q.pop();
                if(currRoot->left)
                {
                    f=1;
                    vis[currRoot->left] = true;
                    q.push(currRoot->left);
                }
                if(currRoot->right)
                {
                    f=1;
                    vis[currRoot->right] = true;
                    q.push(currRoot->right);
                }
                
                Node* parent = mp[currRoot];
                if(parent and !vis[parent])
                {
                    f = 1;
                    vis[parent] = 1;
                }
            }
            if(f) time++;
        }
        
        return time;
    }
    void helper(Node* root,Node* &start,unordered_map<Node*,Node*>&mp,int target)
    {
        if(!root) return;
        if(root->data==target) start = root;
        if(root->left)
        {
            mp[root->left] = root;
        }
        if(root->right)
        {
            mp[root->right] = root;
        }
        
        helper(root->left,start,mp,target);
        helper(root->right,start,mp,target);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node* start;
        unordered_map<Node*,Node*>mp;
        helper(root,start,mp,target);
        int time = findTime(start,mp);
        return time;
    }
int main()
{
    return 0;
}