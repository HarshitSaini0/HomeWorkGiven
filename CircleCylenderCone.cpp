#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.14;
class Circle
{
protected:
    float radius;

public:
    void input()
    {
        cin >> radius;
    }
    void show()
    {
        cout << radius << endl;
    }
    float area()
    {
        float area = radius * radius * PI;
        return area;
    }
};

class Cylinder : public Circle
{
protected:
    float hieght;

public:
    void input()
    {
        Circle::input();
        cin >> hieght;
    }
    void show()
    {
        Circle::show();
        cout << hieght << endl;
    }
    float area()
    {
        float ar1, area;
        ar1 = Circle::area();
        area = 2 * ar1 + (hieght * (2 * PI * radius));
        return area;
    }
};
class Cone : public Cylinder
{
protected:
    float slantHieght;

public:
    void input()
    {
        Cylinder::input();
        slantHieght = sqrt(pow(hieght, 2) + pow(radius, 2));
    }
    void show()
    {
        Cylinder::show();
        cout << slantHieght << endl;
    }
    float area()
    {
        float area;
        area = Circle::area() + (PI * radius * slantHieght);
        return area;
    }
};

int main()
{
    Circle c1;
    Cylinder c2;
    Cone c3;
    c1.input();
    c2.input();
    c3.input();
    c1.show();
    c2.show();
    c3.show();
    cout << "c1 area = " << c1.area() << " c2 area = " << c2.area() << " c3 area = " << c3.area() << endl;

    return 0;
}
