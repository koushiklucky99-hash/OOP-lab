#include <iostream>
#include <algorithm>
using namespace std;

class Sample
{
    int *data;

public:
    Sample()
    {
        data = new int(0);
        cout << "Default Constructor" << endl;
    }

    
    Sample(int value)
    {
        data = new int(value);
        cout << "Parameterized Constructor" << endl;
    }

    
    Sample(const Sample &s)
    {
        data = new int(*s.data);
        cout << "Copy Constructor" << endl;
    }

    
    Sample(Sample &&s) noexcept
    {
        data = s.data;
        s.data = nullptr;
        cout << "Move Constructor" << endl;
    }

    
    Sample& operator=(const Sample &s)
    {
        if (this != &s)
        {
            if (!data)
                data = new int;

            *data = *s.data;
        }
        cout << "Copy Assignment" << endl;
        return *this;
    }

    
    Sample& operator=(Sample &&s) noexcept
    {
        if (this != &s)
        {
            delete data;
            data = s.data;
            s.data = nullptr;
        }
        cout << "Move Assignment" << endl;
        return *this;
    }

    void display()
    {
        if (data)
            cout << "Value: " << *data << endl;
    }

    
    ~Sample()
    {
        delete data;
        cout << "Destructor Called" << endl;
    }
};

int main()
{
    Sample a;
    Sample b(100);
    Sample c(b);
    Sample d(move(b));

    a = c;
    a.display();
    d.display();

    return 0;
}