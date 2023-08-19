#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *start;
void addNode(int val);
void display();
bool search(int num);

int main()
{
    start = NULL;
    int n, val;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter values one by one : ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        addNode(val);
    }
    display();
    bool a;
    a = search(10);
    if (a)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

void addNode(int val)
{
    Node *temp, *ptr;
    temp = new Node;
    temp->data = val;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display()
{
    Node *ptr;
    ptr = start;
    if (ptr == NULL)
    {
        cout << "List is empty " << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}

bool search(int num)
{
    // I don't know sorting in linked lit yet so i will perform linear earch here
    Node *ptr;
    ptr = start;

    while (ptr != NULL)
    {

        if (ptr->data == num)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}
