#include <iostream>
using namespace std;

class node
{
    int data;
    node *next;

public:
    node(int d) : data(d), next(nullptr) {}
    void setdata(int d)
    {
        data = d;
    }

    void setnext(node *n)
    {
        next = n;
    }

    int getdata() 
    {
        return data;
    }

    node *getnext() 
    {
        return next;
    }
};

class list
{
    node *head;
    int count;

public:
    list() : head(nullptr), count(0) {}

    void insert(int d)
    {
        node *newn = new node(d);
        newn->setnext(head);
        head = newn;
        count++;
    }

    void display()
    {
        int node_count = 0;
        node *move = head;

        while (move != nullptr)
        {
            cout << move->getdata() << " ";
            move = move->getnext();
            node_count++;
        }
        cout << "\nTotal nodes: " << node_count << endl;
    }
};

int main()
{
    list l;
    l.insert(10);
    l.insert(20);
    l.insert(30);

    l.display();

        return 0;
}
