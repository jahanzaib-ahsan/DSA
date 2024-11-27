#include<iostream>
using namespace std;
struct node
{
    int data;
    node* prev;
    node* next;
};
node * head=nullptr;
struct node* emptylist(struct node* head ,int data)
{

    node* temp=new node;
    temp->prev=nullptr;
    temp->data=data;
    temp->next=nullptr;
    head=temp;
    return head;
}
struct node* addAtBegining(struct node* head ,int data)
{

    node* temp=new node;
    temp->prev=nullptr;
    temp->data=data;
    temp->next=nullptr;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

int main()
{
    struct node*head=nullptr;
    struct node*ptr=head;
    head=emptylist(head,45);
    head=addAtBegining(head,34);
    ptr=head;
    while(ptr!=nullptr)
    {
        cout<<ptr->data;
        ptr=ptr->next;
    }
    return 0;
}