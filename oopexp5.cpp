#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape
{
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    void area()
    {
        cout << "Circle Area: "
             << 3.14 * radius * radius << endl;
    }
};

class Rectangle : public Shape
{
    float length, breadth;

public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }

    void area()
    {
        cout << "Rectangle Area: "
             << length * breadth << endl;
    }
};

class Triangle : public Shape
{
    float base, height;

public:
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }

    void area()
    {
        cout << "Triangle Area: "
             << 0.5 * base * height << endl;
    }
};

int main()
{
    Shape *s;

    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(4, 5);

    s = &c;
    s->area();

    s = &r;
    s->area();

    s = &t;
    s->area();

    return 0;
}