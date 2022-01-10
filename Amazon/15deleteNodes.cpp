#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};


void linkdelete(struct Node  *head, int M, int N)
    {
        
       Node* temp =head;
       while(temp)
       {
           int count=1;
           while(temp and count<M)
           {
               temp = temp->next;
               count++;
           }
           
           if(!temp) break;
           count=0;
           Node* prev=temp;
           temp=temp->next;
           while(temp and count<N)
           {
               
               temp=temp->next;
               count++;
               
           }
           
           prev->next = temp;
       }
    }

