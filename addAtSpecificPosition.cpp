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
        cout << "Enter item: ";
        cin >> item;
        ptr->data = item;
        ptr->link = head;
        head = ptr;
        cout << "Item inserted\n";
    }
}

void insertAtPosition(int position, int item)
{
    node *ptr = new node;
    ptr->data = item;

    if (ptr == nullptr)
    {
        cout << "Overflow";
        return;
    }

    if (position == 1)
    {
        ptr->link = head;
        head = ptr;
        cout << "Item inserted at position " << position << endl;
        return;
    }

    node *temp = head;
    int count = 1;

    while (temp != nullptr && count < position - 1)
    {
        temp = temp->link;
        count++;
    }

    if (temp == nullptr)
    {
        cout << "Position out of bounds\n";
        delete ptr;
        return;
    }

    ptr->link = temp->link;
    temp->link = ptr;
    cout << "Item inserted at position " << position << endl;
}

void display()
{
    node *ptr = head;
    if (head == nullptr)
    {
        cout << "Nothing to display\n";
    }
    else
    {
        cout << "Printing values:\n";
    }
    while (ptr != nullptr)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->link;
    }
    cout << "NULL\n";
}

void delWholeList()
{
    node *ptr = head;
    if (head == nullptr)
    {
        cout << "Nothing to delete\n";
    }
    while (ptr != nullptr)
    {
        ptr = ptr->link;
        free(head);
        head = ptr;
    }
    cout << "Whole Linked List is deleted\n";
}
void deleteAtLocation(int position)
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (position == 1)
    {
        node *temp = head;
        head = head->link;
        delete temp;
        cout << "Node deleted at position 1." << endl;
        return;
    }

    node *ptr = head;
    node *prev = nullptr;

    for (int i = 1; i < position && ptr != nullptr; ++i)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    if (ptr == nullptr)
    {
        cout << "Position out of range. No node deleted." << endl;
        return;
    }
    prev->link = ptr->link;
    delete ptr;
    cout << "Node deleted at position " << position << "." << endl;
}

void insertAtEnd(int data)
{
    node *ptr = head;
    node *temp = new node;
    temp->data = data;
    temp->link = nullptr;
    while (ptr->link != nullptr)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void deleteFromBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    node *temp = head;
    head = head->link;
    delete temp;
    cout << "Node deleted from the beginning." << endl;
}

void deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->link == nullptr)
    {
        delete head;
        head = nullptr;
        cout << "Node deleted from the end." << endl;
        return;
    }
    node *ptr = head;
    node *prev = nullptr;
    while (ptr->link != nullptr)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = nullptr;
    delete ptr;
    cout << "Node deleted from the end." << endl;
}
int main()
{
    int choice, data, pos;
    do
    {
        cout << "                 Menu                 ";
        cout << "Press 1 to insert at beginning " << endl;
        cout << "Press 2 to insert at end " << endl;
        cout << "Press 3 to display " << endl;
        cout << "Press 4 to delete whole list " << endl;
        cout << "Press 5 to delete specific node " << endl;
        cout << "Press 6 to insert at a specific position " << endl;
        cout << "press 7 to delete from begining  " << endl;
        cout << "press 8 to delete from end " << endl;
        cout << "Press 9 to exit program " << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertatbegining();
            break;
        case 2:
            cout << "Enter the data you want to add at the end of list : ";
            cin >> data;
            insertAtEnd(data);
        case 3:
            display();
            break;
        case 4:
            delWholeList();
            break;
        case 5:
            int value;
            cout << "Enter position number you want to delete from the list: ";
            cin >> pos;
            deleteAtLocation(pos);
            break;
        case 6:
        {
            int position, data;
            cout << "Enter the position to insert: ";
            cin >> position;
            cout << "Enter the value to insert: ";
            cin >> data;
            insertAtPosition(position, data);
            break;
        }
        case 7:
            deleteFromBeginning();
            break;
        case 8:
            deleteFromEnd();
            break;
        case 9:
            cout << "Exiting program ..........\n";
            break;

        default:
            cout << "Invalid choice! Please enter a valid option\n";
            break;
        }
    } while (choice != 9);
    return 0;
}
