#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };
    Node *start;

public:
    LinkedList()
    {
        start = NULL;
    }
    void addAtBeg(int val);
    void addAtEnd(int val);
    void addAtPos(int val, int pos);
    void delAtBeg();
    void delAtEnd();
    void delAtPos(int pos);
    int search(int val);
    void show();
    void sort();
    void reverse();
    LinkedList merg(LinkedList l);
};

int main()
{
    LinkedList l1, l2, l3, l4;
    int val, pos, chk = 0;
    do
    {
        cout << "Press 1 : To Enter at starting " << endl;
        cout << "Press 2 : To Enter at ending " << endl;
        cout << "Press 3 : To Enter at any position " << endl;
        cout << "Press 4 : To display items " << endl;
        cout << "Press 5 : To delete from starting " << endl;
        cout << "Press 6 : To delete from ending " << endl;
        cout << "Press 7 : To delete from any position " << endl;
        cout << "Press 8 : To search for a value " << endl;
        cout << "Press 9 : To Sort " << endl;
        cout << "Press 10 : To Reverse the List " << endl;
        cout << "Press 11: To enter two Lists and then merg them afterwords in a sorted manner " << endl;
        cout << "Press 20 : To Exit " << endl;
        cout << "Enter your choise : ";
        cin >> chk;
        switch (chk)
        {
        case 1:
            cout << "Enter value to enter at beggining  : ";
            cin >> val;
            l1.addAtBeg(val);
            break;
        case 2:
            cout << "Enter value to enter at end : ";
            cin >> val;
            l1.addAtEnd(val);
            break;
        case 3:
            cout << "Enter value : ";
            cin >> val;
            cout << "Enter the position : ";
            cin >> pos;
            l1.addAtPos(val, pos);
            break;
        case 4:
            l1.show();
            break;
        case 5:
            l1.delAtBeg();
            break;
        case 6:
            l1.delAtEnd();
            break;
        case 7:
            cout << "Enter position : ";
            cin >> pos;
            l1.delAtPos(pos);
            break;
        case 8:
            cout << "Enter the number : ";
            cin >> val;
            int index;
            index = l1.search(val);
            cout << "Index = " << index << endl;
            break;
        case 9:
            l1.sort();
            break;
        case 10:
            l1.reverse();
            break;
        case 11:

            cout << "Enter number of elements in List one : ";
            cin >> pos;
            cout << "Enter values now : ";
            for (int i = 0; i < pos; i++)
            {
                cin >> val;
                l2.addAtBeg(val);
            }
            cout << "Enter number of elements in List second : ";
            cin >> pos;
            cout << "Enter values now : ";
            for (int i = 0; i < pos; i++)
            {
                cin >> val;
                l3.addAtBeg(val);
            }
            l4 = l2.merg(l3);
            l4.show();
            break;

        case 20:
            chk = 20;
            break;

        default:
            cout << "Enter proper choise " << endl;
            break;
        }
    } while (chk != 20);

    return 0;
}

void LinkedList::addAtBeg(int val)
{
    Node *temp;
    temp = new Node;
    temp->data = val;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}

void LinkedList::addAtEnd(int val)
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

void LinkedList::addAtPos(int val, int pos)
{
    if (pos <= 0)
    {
        cout << "INVALID POSITION" << endl;
        return;
    }
    Node *temp, *ptr;
    ptr = start;

    for (int i = 1; i < pos - 1; i++)
    {
        if (ptr != NULL)
        {
            ptr = ptr->next;
        }
        else
        {
            cout << "INVALID POSITION" << endl;
            return;
        }
    }
    temp = new Node;
    temp->data = val;
    if (start == NULL && pos == 1)
    {
        temp->next = NULL;
        start = temp;
        return;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
void LinkedList::show()
{
    Node *ptr;

    if (start == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
void LinkedList::delAtBeg()
{
    if (start == NULL)
    {
        cout << "LIST IS EMPTY" << endl;
        return;
    }
    Node *ptr;
    ptr = start;
    start = start->next;
    delete ptr;
}
void LinkedList::delAtEnd()
{
    if (start == NULL)
    {
        cout << "LIST IS EMPTY" << endl;
        return;
    }
    Node *ptr;
    ptr = start;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    delete ptr->next;
    ptr->next = NULL;
}
void LinkedList::delAtPos(int pos)
{
    if (pos <= 0 || start == NULL)
    {
        cout << "LIST IS EMPTY" << endl;
        return;
    }

    if (pos == 1)
    {
        delAtBeg();
        return;
    }
    Node *ptr, *temp;
    ptr = start;

    for (int i = 1; i < pos - 1; i++)
    {
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        else
        {
            cout << "INVALID INDEX" << endl;
            return;
        }
    }

    if (ptr == NULL)
    {
        delAtEnd();
        return;
    }
    temp = ptr->next;
    ptr->next = temp->next;

    delete temp;
}
int LinkedList::search(int val)
{
    Node *ptr;
    int counter = 0;
    ptr = start;
    while (ptr != NULL)
    {

        if (ptr->data == val)
        {
            return counter;
        }
        counter++;
        ptr = ptr->next;
    }
    return -1;
}

void LinkedList::sort()
{
    Node *i, *j;
    for (i = start; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void LinkedList::reverse()
{
    Node *ptr, *newPtr;
    newPtr = NULL;
    while (start != NULL)
    {
        ptr = start;
        start = start->next;
        ptr->next = newPtr;
        newPtr = ptr;
    }
    start = newPtr;
}

LinkedList LinkedList::merg(LinkedList l)
{
    Node *i, *j;
    sort();
    l.sort();
    i = start;
    j = l.start;
    LinkedList result;
    while (i != NULL || j != NULL)
    {
        if (j == NULL)
        {
            while (i != NULL)
            {
                result.addAtEnd(i->data);
                i = i->next;
            }
        }
        else if (i == NULL)
        {
            while (j != NULL)
            {
                result.addAtEnd(j->data);
                j = j->next;
            }
        }
        else
        {
            if (i->data >= j->data)
            {
                result.addAtEnd(j->data);
                j = j->next;
            }
            else if (j->data > i->data)
            {

                result.addAtEnd(i->data);
                i = i->next;
            }
        }
    }
    return result;
}
