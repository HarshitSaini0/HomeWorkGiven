#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
protected:
    int empID;
    char *name;
    long int salary;

public:
    void input()
    {
        cout << "Enter employee name ID : ";
        cin >> empID;
        cout << "Enter employee name : ";
        char temp[50];
        cin >> temp;
        int n = strlen(temp);
        name = new char[n];
        strcpy(name, temp);
        cout << "Enter employee salary : ";
        cin >> salary;
    }
    void show()
    {
        cout << "EmpID \t Name \t \t Salary " << endl;
        cout << empID << " \t " << name << " \t \t " << salary << endl;
    }
};
class Salesman : public Employee
{
public:
    void input()
    {
        long int mSales;
        Employee::input();
        cout << "Enter monthy sales : ";
        cin >> mSales;
        salary += 0.1 * (mSales);
    }
    void show()
    {
        Employee::show();
    }
};
class Worker : public Employee
{
public:
    void input()
    {
        int hrs;
        Employee::input();
        cout << "Enter the number of hours worked extra(monthly) : ";
        cin >> hrs;
        salary += hrs * 500;
    }
    void show()
    {
        Employee::show();
    }
};

int main()
{
    Employee e;
    Salesman s;
    Worker w;
    e.input();
    e.show();
    s.input();
    s.show();
    w.input();
    w.show();
    return 0;
}
