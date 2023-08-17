#include <iostream>
using namespace std;

class Student
{
    int rollNo;
    char name[50];
    float marks;
    static float passing_marks;

public:
    void input();
    void show();
    static void enterPassingMarks();
};

float Student::passing_marks;

int main()
{
    Student a;
    Student::enterPassingMarks();
    a.input();
    a.show();

    return 0;
}

void Student::input()
{
    cout << "Roll no : ";
    cin >> rollNo;
    cout << "Name : ";
    cin >> name;
    cout << "Marks : ";
    cin >> marks;
}

void Student::show()
{
    cout << "Roll No " << rollNo << " , " << name;
    if (marks >= passing_marks)
    {
        cout << " Passed with " << marks << endl;
    }
    else
    {
        cout << " have to reappear for the exam as student scored " << marks << endl;
    }
}

void Student::enterPassingMarks()
{
    cout << "Enter passing marks : " << endl;
    cin >> passing_marks;
}
