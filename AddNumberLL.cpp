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
Node * AddLL_1(Node *l1,Node *l2)
{
    Node *head=new Node((l1->val+l2->val)%10);
    int carry=(l1->val+l2->val)/10;
    Node *temp=head;
    l2=l2->next;
    l1=l1->next;
    while(l1!=NULL || l2!=NULL)
    {
        if(l1==NULL){
            temp->next=new Node((l2->val+carry)%10);
            carry=(l2->val+carry)/10;
            l2=l2->next;
        } else if(l2==NULL)
        
        {
            temp->next=new Node((l1->val+carry)%10);
            carry=(l1->val+carry)/10;
            l1=l1->next;
        }
        else
        {
            temp->next=new Node((l1->val+l2->val+carry)%10);
            carry=(l1->val+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
        }
        temp=temp->next;
    }
    if(carry!=0)
    temp->next=new Node(carry);
    return head;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head1=NULL,*head2=NULL,*head=NULL;
    vector<int>l1={2,4,3},l2={5,6,7,9};
    head1=appendArray(head1,l1);
    head2=appendArray(head2,l2);
    PrintLL(head1);
    PrintLL(head2);
    head=AddLL_1(head1,head2);
    PrintLL(head);
    return 0;
}