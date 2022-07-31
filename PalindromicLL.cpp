#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node {
    int val;
    Node * next;
    Node(int data):val(data),next(NULL){}
};
Node *append(Node * head,int data)
{
    if(head==NULL)
    {
        head=new Node(data);
        return head;
    }
    Node *temp=head;
    while(head->next!=NULL)
    head=head->next;
    head->next=new Node(data);
    return temp;
}
Node * appendArray(vector<int>arr)
{
    Node *head=NULL;
    for(auto i:arr)
    head=append(head,i);
    return head;
}
void PrintLL(Node *head)
{
    if(head==NULL)cout<<"No Elements in the List"<<endl;
    else
    {
        while(head->next!=NULL)
        {
            cout<<head->val<<" -> ";
            head=head->next;
        }
        cout<<head->val<<endl;
    }
}
bool PalindromicLL(Node *head)
{
    if(head==NULL || head->next==NULL) return false;
    Node *fast=head;
    Node *slow=head;
    while(fast->next && fast->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    Node *prev=NULL,*temp=slow->next;
    while(temp!=NULL)
    {
        Node *next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    slow->next=prev;
    slow=slow->next;
    Node *d1=head;
    while(slow)
    {
        if(slow->val != d1->val) return false;
        slow=slow->next;
        d1=d1->next;
    }
    return true;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    vector<int> arr={1,2,3,3,7,1};
    head=appendArray(arr);
    PrintLL(head);
    cout<<PalindromicLL(head);
    return 0;
}