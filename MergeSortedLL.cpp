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
Node * Merge_1(Node *head1,Node *head2)
{
    Node *temp,*newHead;
    temp=new Node(0);
    newHead=temp;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->val >= head2->val){ 
            temp->next=head2;
            head2=head2->next;
        }
        else {
            temp->next=head1;
            head1=head1->next;
        }
        temp=temp->next;
    }
    if(head1!=NULL) temp->next=head1;
    if(head2!=NULL) temp->next=head2;
    return newHead->next;
}
Node * Merge_2(Node *l1,Node *l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    if(l1->val>l2->val) swap(l1,l2);
    Node *newhead=l1;
    while(l1 && l2)
    {
        Node *prev=NULL;
        while(l1 && l1->val<=l2->val)
        {
            prev=l1;
            l1=l1->next;
        }
        prev->next=l2;
        swap(l1,l2);
    }
    return newhead;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head1=NULL,*head2=NULL,*head;
    vector<int>arr={5,7,9},arr2={3,4,8,10};
    head1=appendArray(head1,arr);
    head2=appendArray(head2,arr2);
    PrintLL(head1);
    PrintLL(head2);
    head=Merge_1(head1,head2);
    PrintLL(head);
    return 0;
}