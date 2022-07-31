#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
    int val;
    Node *next;
    Node(int data):val(data),next(NULL){}
};
Node *append(Node * head,int data)
{
    if(head==NULL)
        return new Node(data);
    Node *newNode=new Node(data);
    auto *temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=newNode;
    return head;
}
Node * appendList(vector<int> arr)
{
    Node *head=NULL;
    for(auto i:arr)
    head=append(head,i);
    return head;
}
void PrintLL(Node *head)
{
    if(head==NULL)
    cout<<"No Elements";
    else
    {
        while(head->next!=NULL){
            cout<<head->val<<" -> ";
        head=head->next;
        }
        cout<<head->val;
    }
    cout<<endl;
}
Node * Rotate(Node *head,int k)
{
     if(!head || !head->next || k==0) return head;
    int count=0;
    auto *d1=head;
    while(d1!=NULL)
    {
        d1=d1->next;
        count++;
    }
    if(k>count) k=k%count;
    while(k--)
    {
        Node *temp=head;
        Node *prev=NULL;
        while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
        }
        auto *newHead=temp;
        prev->next=NULL;
        newHead->next=head;
        head=newHead;
    }
    return head;
}
Node *Rotate_optimal(Node *head,int k)
{
    if(head==NULL || head->next== NULL || k==0) return head;
    Node * temp=head;
    int count=1;
    while(temp->next &&++count)
    temp=temp->next;
    temp->next=head;
    k=k%count;
    k=count-k;
    while(k--) temp=temp->next;
    head=temp->next;
    temp->next=NULL;
    return head;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    vector<int> arr={1,2,3,4,5};
    head=appendList(arr);
    PrintLL(head);
    head=Rotate_optimal(head,2);
    PrintLL(head);
    return 0;
}