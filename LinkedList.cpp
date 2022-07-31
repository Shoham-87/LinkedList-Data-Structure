#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void insertBefore(Node ** head,int prev_data,int new_data);
void append(Node ** head,int newdata);
void Push(Node **head,int data);
void append(Node ** head,int newdata)
{
    Node * node=new Node();
    node->data=newdata;
    node->next=NULL;
    if((*head) ==  NULL)
    {
        (*head)=node;
        return;
    }
    Node *temp=(*head);
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=node;
    return;
}
void Push(Node **head,int data)
{
    Node *node=new Node();
    node->data=data;
    node->next=NULL;
    if((*head) ==  NULL)
    {
        (*head)=node;
        return;
    }
    node->next=*head;
    *head=node;
}
void insertBefore(Node ** head,int prev_data,int new_data)
{
    Node *node=new Node();
    node->data=new_data;
    node->next=NULL;
    if((*head)->data == prev_data)
    {   
        node->next=(*head);
        (*head)=node;
        return;
    }
    Node *temp=(*head);
    while(temp!=NULL && temp->next->data!=prev_data)
    temp=temp->next;
    if(temp==NULL)
    return;
    node->next=temp->next;
    temp->next=node;
}
void insertAfter(Node ** head,int prev,int new_data)
{
    Node *node=new Node();
    node->data=new_data;
    node->next=NULL;
    Node *temp=(*head);
    while(temp!=NULL && temp->data!=prev)
        temp=temp->next;
    node->next=temp->next;
    temp->next=node;
}
void deleteNode(Node ** head,int del_node)
{
    Node *prev=NULL,*cur=(*head);
    if(cur!=NULL && cur->data==del_node)
    {
        *head=cur->next;
        delete cur;
        return;
    }
    while(cur!=NULL && cur->data != del_node)
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    return;
    prev->next=cur->next;
    delete cur;
    return;
}
void print(Node *head)
{
    while(head->next!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<head->data;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node * head=NULL;
    append(&head,8);
    append(&head,9);
    Push(&head,89);
    Push(&head,6);
    insertBefore(&head,8,19);
    insertAfter(&head,19,10);
    insertAfter(&head,10,17);
    print(head);
    cout<<endl;
    deleteNode(&head,6);
    print(head);
    return 0;
}
// class LinkedList
// {
// public:
//     LinkedList(){};
//     Node *head = NULL;
//     void append(int new_data)
//     {
//         Node *start = head;
//         Node *node = new Node();
//         node->data = new_data;
//         node->next = NULL;
//         if (head == NULL)
//         {
//             head = node;
//             return;
//         }
//         while (start->next != NULL)
//             start = start->next;
//         start->next = node;
//     }
//     void push(int new_data)
//     {
//         Node *node = new Node;
//         node->data = new_data;
//         node->next = NULL;
//         if (head == NULL)
//         {
//             head = node;
//             return;
//         }
//         node->next = head;
//         head = node;
//     }
//     void insertAfter(int old_data, int new_data)
//     {
//         Node *node, *start = head;
//         node->data = new_data;
//         while (start!= NULL && start->data != old_data )
//         {
//             start = start->next;
//         }
//         node->next = start->next;
//         start->next = node;
//         return;
//     }
//     void Print()
//     {
//         Node *start=head;
//         while (start != NULL)
//         {
//             cout << start->data << "->";
//             start = start->next;
//         }
//         cout << endl;
//     }
// };