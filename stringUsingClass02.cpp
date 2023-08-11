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
    int length();
    String operator+(String);
    bool operator==(String);
    bool operator>(String);
    bool operator<(String);
    void upperCase();
    void lowerCase();
    void titleCase();
    void toggleCase();
    friend istream &operator>>(istream &a, String &b);
    friend ostream &operator<<(ostream &a, String &b);
    void setCharAt(int index, char val);
    char charAt(int index);
    String subString(int start, int end);
    int indexOfString(String str01);
    // friend char operator_(String &a,int &b);
};
istream &operator>>(istream &a, String &b)
{
    cin >> b.str;
    return a;
}
ostream &operator<<(ostream &a, String &b)
{
    cout << b.str << endl;
    return a;
}
// char operato_ (String &a,int &b){
//     if(b>=0 && b<a.length()){
//         return a.str[b];
//     }
//     else{
//         return '\0';
//     }
// }
int main()
{
    String a, b;
    int x;
    cout << "Enter the String : ";
    cin >> a;
    cout << "Enter the substing for what you want to find index : ";
    cin >> b;
    x = a.indexOfString(b);
    cout << "Index = " << x;

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

int String::length()
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
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

void String::setCharAt(int index, char val)
{
    if (index >= 0 && index < length())
    {
        str[index] = val;
    }
    else
    {
        cout << "INVALID INDEX " << endl;
    }
}
char String::charAt(int index)
{
    if (index >= 0 && index < length())
    {
        return str[index];
    }
    else
    {
        return '\0';
    }
}
String String::subString(int start, int end)
{
    String ret;
    int i, j;
    if (start < end && (start >= 0 && start < length()) && (end >= 0 && end < length()))
    {
        for (i = start, j = 0; i < end; i++, j++)
        {
            ret.str[j] = str[i];
        }
        ret.str[j] = '\0';
        return ret;
    }
    else
    {
        return ret;
    }
}

int String::indexOfString(String str01)
{
    int i, j, chk = 0, n1 = length(), n2 = str01.length();
    if (n2 > n1)
    {
        return -1;
    }
    for (i = 0; i < n1; i++)
    {
        chk = 0;
        if (str[i] == str01.str[0])
        {
            for (j = 0; j < n2; j++)
            {
                if (str[j + i] == str01.str[j])
                {
                    chk++;
                    // cout<<chk<<endl;
                }
                else
                {
                    chk = 0;
                    // cout<<"Break"<<endl;
                    break;
                }
            }
            if (chk == n2)
            {
                return i;
            }
        }
    }
    return -1;
}
