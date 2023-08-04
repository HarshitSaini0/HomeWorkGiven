#include <iostream>
using namespace std;

class Distance
{
    int m;
    int km;

public:
    Distance()
    {
        m = km = 0;
    }

    Distance(int a)
    {
        m = a;
        km = 0;

        format();
    }

    Distance(int a, int b)
    {
        km = a;
        m = b;
        format();
    }

    void format();
    void show();
    void input();
    bool operator==(Distance);
    bool operator<(Distance);
    bool operator>(Distance);
    Distance operator+(Distance);
    Distance operator-(Distance);
    Distance operator++();
};

int main()
{
    Distance a(1, 100), b(1100), c;
    c.show();
    c.input();
    

    return 0;
}

void Distance::format()
{
    while (m >= 1000)
    {
        km++;
        m /= 1000;
    }
}

void Distance::show()
{
    format();

    cout << km << " Km " << m << " m" << endl;
}
void Distance::input()
{
    cout << "KM : ";
    cin >> km;
    cout << "Meters : ";
    cin >> m;
    if (km < 0 || m < 0)
    {
        cout << "Enter positve value !!! " << endl;
        Distance::input();
    }
    format();
}
bool Distance::operator==(Distance a)
{
    format();
    a.format();
    if (km == a.km && m == a.m)
    {
        return true;
    }
    return false;
}
bool Distance::operator>(Distance a)
{
    format();
    a.format();
    if (km > a.km)
    {
        return true;
    }
    else if (km == a.km && m > a.m)
    {
        return true;
    }
    return false;
}
bool Distance::operator<(Distance a)
{
    format();
    a.format();
    if (km < a.km)
    {
        return true;
    }
    else if (km == a.km && m < a.m)
    {
        return true;
    }

    return false;
}
Distance Distance::operator+(Distance a)
{

    Distance temp;
    temp.km = km + a.km;
    temp.m = m + a.m;
    temp.format();
    return temp;
}
Distance Distance::operator-(Distance a)
{
    Distance temp;
    if ((km > a.km && m > a.m) || (km == a.km && m > a.m))
    {
        temp.km = km - a.km;
        temp.m = m - a.m;
    }
    else
    {
        temp.km = a.km - km;
        temp.m = a.m - m;
    }
    temp.format();
    return temp;
}
Distance Distance::operator++()
{
    km++;
}
