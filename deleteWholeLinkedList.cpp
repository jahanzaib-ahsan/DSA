#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
struct node *head = nullptr;
void insertatbegining()
{
    node *ptr;
    int item;
    ptr = new node;
    if (ptr == nullptr)
    {
        cout << "Overflow";
    }
    else
    {
        cout << "Enter item : ";
        cin >> item;
        ptr->data = item;
        ptr->link = head;
        head = ptr;
        cout << " item inserted ";
    }
}
void display()
{
    node *ptr=head;
    if(head==nullptr)
    {
        cout<<"Nothing to display"<<endl; 
    }
    else
    {
        cout<<"Printing values whilr (ptr != nullptr )"<<endl;;
    }
    while(ptr != nullptr)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->link;
    }
}
void delWholeList()
{
    node *ptr=head;
    if(head==nullptr)
    {
        cout<<"Nothing to delete"<<endl; 
    }
    while(ptr!=nullptr)
    {
        ptr=ptr->link;
        free(head);
        head=ptr;
    }
    cout<<"Whole Linked List is deleted ";
}

int main()
{
    int choice;
    do
    { 
    cout<<"                 Menu                 "<<endl;
    cout<<"Press 1 to insert at begining "<<endl;
    cout<<"press 2 to display "<<endl;
    cout<<"press 3 to delete whole list "<<endl;
    cout<<"prest 4 to exit program "<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        insertatbegining();
        break;
    case 2 :
        display();
        break;  
    case 3 :
        delWholeList();
        break;  
    case 4: 
        cout<<"Exiting program .......... "<<endl;
        break;
    default:
        cout<<"invalid choice ! Please enter  1,2 or 3"<<endl;
        break;
    }
    } while (choice!=4);
    return 0;
}