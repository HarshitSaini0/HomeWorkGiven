#include <iostream>
#include <string.h>
using namespace std;

class String
{
    char str[50];

public:
    String()
    {
        str[0] = '\0';
    }

    void input();
    void show();
    String operator+(String);
    bool operator==(String);
    bool operator>(String);
    bool operator<(String);
    void upperCase();
    void lowerCase();
    void titleCase();
    void toggleCase();
};
int main()
{
    String a, b;
    a.input();
    b.input();
    a.show();
    b.show();
    a.toggleCase();
    b.titleCase();
    a.show();
    b.show();

    return 0;
}

void String::input()
{
    cin.getline(str, 50);
}

void String::show()
{
    cout << str << endl;
}
String String::operator+(String val)
{
    String temp;
    int i, j;
    for (i = 0; str[i] != '\0'; i++)
    {
        temp.str[i] = str[i];
    }
    for (j = 0; val.str[j] != '\0'; j++)
    {
        temp.str[i++] = val.str[j];
    }
    temp.str[i] = '\0';
    return temp;
}
bool String::operator==(String val)
{
    if (strcmp(str, val.str) == 0)
    {
        return 1;
    }
    return 0;
}
bool String::operator>(String val)
{
    if (strcmp(str, val.str) > 0)
    {
        return 1;
    }
    return 0;
}
bool String::operator<(String val)
{
    if (strcmp(str, val.str) < 0)
    {
        return 1;
    }
    return 0;
}
void String::upperCase()
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (int(str[i]) > 96 && int(str[i]) < 123)
        {
            str[i] -= 32;
        }
    }
}
void String::lowerCase()
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (int(str[i]) > 64 && int(str[i]) < 91)
        {
            str[i] += 32;
        }
    }
}
void String::titleCase()
{
    lowerCase();
    str[0] -= 32;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && int(str[i + 1]) > 96 && int(str[i + 1]) < 123)
        {
            str[i + 1] -= 32;
        }
    }
}
void String::toggleCase()
{
    upperCase();
    str[0] += 32;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && int(str[i + 1]) > 64 && int(str[i + 1]) < 91)
        {
            str[i + 1] += 32;
        }
    }
}
