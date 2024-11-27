#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};
struct node *head = nullptr;

void insertAtEnd(int data)
{
    node *ptr = head;
    node *temp = new node;
    temp->data = data;
    temp->link = nullptr;

    if (head == nullptr)
    {
        head = temp;
        return;
    }

    while (ptr->link != nullptr)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void insertAtSpecific(int d, int p)
{
    int count = 1; // Initialize count to 1
    node *ptr = head;
    node *ptr2 = new node;
    ptr2->data = d;

    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (p == 1)
    {
        ptr2->link = head;
        head = ptr2;
        cout << "Item inserted at position " << p << endl;
        return;
    }

    while (ptr != nullptr && count < p - 1)
    {
        ptr = ptr->link;
        count++;
    }

    if (ptr == nullptr || ptr->link == nullptr && count < p - 1)
    {
        cout << "Position out of bounds." << endl;
        return;
    }

    ptr2->link = ptr->link;
    ptr->link = ptr2;
    cout << "Item inserted at position " << p << endl;
}

void display()
{
    node *ptr = head;
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    while (ptr != nullptr)
    {
        cout << ptr->data << "->";
        ptr = ptr->link;
    }
    cout << "Null" << endl;
}

int main()
{
    int choice, data, pos;
    do
    {
        cout << "Press 1 to insert in list: " << endl;
        cout << "Press 2 to insert at specific position: " << endl;
        cout << "Press 3 to display the list: " << endl;
        cout << "Press 4 to exit the program: " << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data you want to enter: ";
            cin >> data;
            insertAtEnd(data);
            break;
        case 2:
            cout << "Enter the data you want to enter: ";
            cin >> data;
            cout << "Enter the position at which you want to enter data: ";
            cin >> pos;
            insertAtSpecific(data, pos);
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting Program........" << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
