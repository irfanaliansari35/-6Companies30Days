 void connect(Node *root)
    {
       
       if(!root) return;
       
       queue<Node*>q;
       q.push(root);
       while(!q.empty())
       {    Node* prev=NULL;
            int n=q.size();
           while(n--)
           {
               Node* curr=q.front();
               q.pop();
               
               if(prev) prev->nextRight=curr;
               prev=curr;
               
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
           }
           
       }
      
    }