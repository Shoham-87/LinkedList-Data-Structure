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
Node * Clone_Simple(Node *head)
{
    Node *cur=new Node(0);
    Node *newhead=cur;
    while(head!=NULL)
    {
        cur->next=new Node(head->val);
        cur=cur->next;
        head=head->next;
    }
    return newhead->next;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    vector<int> arr={1,2,3,4,5};
    head=appendList(arr);
    PrintLL(head);
    Node *head1=Clone_Simple(head);
    PrintLL(head1);
    return 0;
}