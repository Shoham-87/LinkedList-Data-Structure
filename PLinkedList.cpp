#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
    int val;
    Node * next;
    Node(int data):val(data),next(NULL){}
};
Node *InsertAfter(Node *head,int data,int k=0)
{
    if(!head)
        return new Node(data);
    Node *temp=head;
    while(temp!=NULL && temp->val!=k)
    temp=temp->next;
    if(temp==NULL) return head;
    Node *newNode=new Node(data);
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}
Node *append(Node *head,int data)
{
    if(!head) return new Node(data);
    auto *temp=head;
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
Node *InsertBefore(Node *head,int data,int k=0)
{
    if(!head)return new Node(data);
    Node *newNode=new Node(data);
    if(head->val==k)
    {
        newNode->next=head;
        head=newNode;
        return head;
    }
    Node *temp=head;
    while(temp!=NULL && temp->next->val!=k)
        temp=temp->next;
    if(temp==NULL) return head;
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}
Node * DeleteNode(Node* head,int data)
{
    Node * temp=head;
    if(head->val==data)
    {
        head=head->next;
        delete temp;
        return head;
    }
    Node *prev=NULL;
    while(temp!=NULL && temp->val!=data){
        prev=temp;
    temp=temp->next;
    }
    if(temp==NULL) return head;
    prev->next=temp->next;
    delete temp;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    vector<int> arr={1,2,3,9,7};
    head=appendArray(head,arr);
    PrintLL(head);
    head=DeleteNode(head,1);
    // head=InsertAfter(head,1);
    // head=InsertAfter(head,2,1);
    // head=InsertAfter(head,3,2);
    // head=InsertBefore(head,0,1);
    // head=InsertBefore(head,8,3);
    PrintLL(head);
    head=DeleteNode(head,3);
    PrintLL(head);
    return 0;
}