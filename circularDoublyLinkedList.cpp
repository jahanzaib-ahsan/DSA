#include<iostream>
using namespace std;
struct node
{
    int data;
    node* prev;
    node* next;
};
struct node* emptylist(int data)
{

    node* temp=new node;
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct node* addAtBeg(struct node* tail,int data)
{
    struct node* newn=emptylist(data);
    if(tail==nullptr)
    {
        return newn;
    }
    else
    {
        struct node* temp=tail->next;
        newn->prev=tail;
        newn->next=temp;
        temp->prev=newn;
        tail->next=newn;
        return tail;
    }
}
struct node* deleteNode(struct node* tail ,int pos)
{
    struct node* temp=tail->next;
    while(pos > 1)
    {
        temp=temp->next;
        pos--;
    }
    struct node* temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    if(temp==tail)
    tail=temp2;
    return tail;
    
}
void print(struct node* tail)
{
    if(tail==nullptr)
    {
        cout<<" List is empty ";
    }
    else
    {
        struct node* temp=tail->next;
        do
        {
           cout<<temp->data<<" ";
           temp=temp->next;
        } while (temp!=tail->next);
        
    }
}
int main()
{
    struct node* tail=nullptr;
    tail=emptylist(45);
    tail=addAtBeg(tail,44);
    tail=addAtBeg(tail,43);
    cout<<"List before deletion : ";
    print(tail);
    tail=deleteNode(tail,2);
    cout<<endl;
    cout<<"List after deletion : ";
    print(tail);
    return 0;
}