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
bool detectCycle(Node *head)
{
    set<Node *>s;
    while(head!=NULL)
    {
        if(s.find(head)!=s.end()) return true;
        s.insert(head);
        head=head->next;
    }
    return false;
}
bool detectCycle_optimal(Node *head)
{
    if(head==NULL || head->next==NULL) return false;
    Node *fast=head;
    Node *slow=head;
    while(fast->next && fast->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    vector<int> arr={1,3,2,4,7,5};
    head=appendArray(arr);
    Node *temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=head->next;
    // PrintLL(head);
    cout<<detectCycle(temp);
    return 0;
}