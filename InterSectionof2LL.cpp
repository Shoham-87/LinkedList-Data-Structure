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
Node * InterSection_1(Node *l1,Node *l2)
{
    set<Node *> s;
    if(l1==NULL || l2==NULL) return NULL;
    while(l1!=NULL)
    {
        s.insert(l1);
        l1=l1->next;
    }
    Node *InterNode=NULL;
    while(l2!=NULL)
    {
        if(s.find(l2) != s.end()) {InterNode=l2; break;}
        l2=l2->next;
    }
    return InterNode;
}
Node *InterSection_2(Node *l1,Node *l2)
{
    if(l1==NULL || l2== NULL) return NULL;
    auto d1=l1;
    auto d2=l2;
    while(d1!=d2)
    {
        d1=d1==NULL?l2:d1->next;
        d2=d2==NULL?l1:d2->next;
    }
    return d1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    vector<int>arr={1,2,3,4,5};
    head=appendArray(head,arr);
    PrintLL(head);
    // head=Reverse(head);
    PrintLL(head);
    return 0;
}