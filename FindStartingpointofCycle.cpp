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
Node * FindStartNodeCycle(Node *head)
{
    if(head==NULL || head->next==NULL) return head;
    auto *slow=head;
    auto *fast=head;
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast)
        {
            fast=head;
            while(fast!=slow)
            {
                fast=fast->next;
                slow=slow->next;
            }
                return slow;
        }
    }
    return NULL;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    head=appendArray(head,arr);
    PrintLL(head);
    Node *temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=head->next->next;
    Node *x=FindStartNodeCycle(head);
    cout<<x->val;
    return 0;
}