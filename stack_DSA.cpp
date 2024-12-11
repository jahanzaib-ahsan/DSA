#include <iostream>
using namespace std;
class stack
{
public:
    const static int size = 5;
    int arr[size];
    int top = -1;
    void push(int n)
    {
        int item = n;
        if (top == size - 1)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            top = top + 1;
            arr[top] = item;

            cout << item << " " << "Item Inserted" << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << " Stack underflow "<<endl;
        }
        else
        {
            int item = arr[top];
            top = top - 1;
            cout << item << " " << "Item deleted" << endl;
        }
    }
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty there is no peek element " << endl;
        }
        else 
        cout << "Peek element in stack is " << arr[top] << endl;
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack elements are: " << endl;
            for (int i = 0; i <= top; i++)
            {
                cout << "[" << arr[i] << "] " << endl;
            }
            cout << endl;
        }
    }
};
int main()
{
    stack t;
    int choice, num;
    do
    {
        cout << "Press 1 to put an element into stack : " << endl;
        cout << "Press 2 to pop an element into stack : " << endl;
        cout << "Press 3 to display element in stack : " << endl;
        cout << "Press 4 to display only peek element : " << endl;
        cout << "Press 5 to exit program : " << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number you want to push in stack : " << endl;
            cin >> num;
            t.push(num);
            break;
        case 2:
            t.pop();
            break;
        case 3:
            t.display();
            break;
        case 4:
            t.peek();
            break;
        case 5:
            cout << "Exiting program"<<endl;
            break;
        default:
            cout << "Invalid input choose between 1,2,3 and 4 "<<endl;
            break;
        }
    } while (choice != 5);

    return 0;
}