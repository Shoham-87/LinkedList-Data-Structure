#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
    int val;
    int d;
    Node *next;
    Node *bottom;
    Node(int data):val(data){
        next=bottom=NULL;
    }
};
Node *Merge(Node *l1,Node *l2)
{
    Node *d=new Node(0);
    Node *head=d;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val<=l2->val)
        {
            d->bottom=l1;
            d=d->bottom;
            l1=l1->bottom;
        }
        else
        {
            d->bottom=l2;
            d=d->bottom;
            l2=l2->bottom;
        }
    }
    if(l1) {d->bottom=l1;}
    else {d->bottom=l2;}
    return head->bottom;
}
Node *Flatten(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    head->next=Flatten(head->next);
    head=Merge(head,head->next);
    return head;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
