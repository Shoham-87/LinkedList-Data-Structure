#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
    int val;
    Node *next;
    Node(int data):val(data){
        next=NULL;
    }
};
void PrintLL(Node *head);
Node *append(Node *head,int data)
{
    if(!head) return new Node(data);
    auto temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=new Node(data);
    return head;
}
Node * appendArray(Node *head,vector<int>&arr)
{
    for(auto i:arr)
    head=append(head,i);
    return head;
}
void PrintLL(Node *head)
{
    if(!head){
        cout<<head->val;
        return;
    }
    while(head->next!=NULL)
    {
        cout<<head->val<<" -> ";
        head=head->next;
    }
    cout<<head->val<<endl;
}
Node * ReverseNodeinKgrp(Node *head,int k)
{
    if(head==NULL || k==1) return head;
    Node * d=new Node(0);
    d->next=head;
    Node *prev=d,*cur=d,*next=d;
    int count=0;
    while(cur->next!=NULL)
    {
        cur=cur->next;
        count++;
    }
    while(count>=k)
    {
        cur=prev->next;
        next=cur->next;
        for(int i=1;i<k;i++)
        {
            cur->next=next->next;
            next->next=prev->next;
            prev->next=next;
            next=cur->next;
        }
        count-=k;
        prev=cur;
    }
    return d->next;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    vector<int>arr={1,2,3,4,5,6,7,8};
    head=appendArray(head,arr);
    PrintLL(head);
    head=ReverseNodeinKgrp(head,3);
    PrintLL(head);
    return 0;
}