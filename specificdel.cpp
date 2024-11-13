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
        cout<<"Printing values while (ptr != nullptr )"<<endl;;
    }
    while(ptr != nullptr)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->link;
    }
}
void delSpecific(int value)
{
    node *ptr=head;
    node *prev=nullptr;
    if(ptr==nullptr)
    {
        cout<<"List is already empty "<<endl;
    }
    if(head->data==value)
    {
        head=head->link;
        delete ptr;
        cout<<"The node with the value is deleted successfully "<<endl;
    }
    while(ptr!=nullptr && ptr->data!=value)
    {
        prev=ptr;
        ptr=ptr->link;
    }   
    if(ptr==nullptr) 
    {
        cout<<"Value not found in the list "<<endl;
    }
    prev->link=ptr->link;
    delete ptr;
    cout<<"The node with the value is deleted successfully "<<endl;
}


int main()
{
    int choice;
    do
    { 
    cout<<"                 Menu                 "<<endl;
    cout<<"Press 1 to insert at begining "<<endl;
    cout<<"press 2 to display "<<endl;
    cout<<"press 3 to delete a specific location "<<endl;
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
        int value;
        cout<<"Enter value you want to delete from the list ";
        cin>>value;
        delSpecific(value);
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