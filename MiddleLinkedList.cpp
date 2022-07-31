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
Node * InsertMiddle(Node * head,int data)
{
    Node *fast,*slow;
    fast=slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    Node *newNode=new Node(data);
    newNode->next=slow->next;
    slow->next=newNode;
    return head;
}
Node *MiddleElement(Node *head)
{
    // Node *temp=new Node(0);
    // temp->next=head;
    // Node *temp1=head;
    // int n=0;
    // while(temp1!=NULL)
    // {
    //     temp1=temp1->next;
    //     ++n;
    // }
    // if(n%2==0) n=n/2 +1;
    // else n=ceil(n/2.0);
    // for(int i=1;i<=n;i++)
    //     temp=temp->next;
    // temp->next=NULL;
    // return temp;
    Node *fast,*slow;
    fast=slow=head;
    while(fast!=NULL && fast->next!=NULL )
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    vector<int>arr={1,2,3,4,5,6};
    head=appendArray(head,arr);
    PrintLL(head);
    head=MiddleElement(head);
    PrintLL(head);
    return 0;
}