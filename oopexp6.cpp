#include <iostream>
using namespace std;

class Matrix
{
    int a[2][2];

public:
    void getData()
    {
        cout << "Enter 4 elements: ";

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    Matrix operator+(Matrix m)
    {
        Matrix temp;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp.a[i][j] = a[i][j] + m.a[i][j];
            }
        }

        return temp;
    }

    void display()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int add(int a, int b)
{
    return a + b;
}

float add(float a, float b)
{
    return a + b;
}

int main()
{
    Matrix m1, m2, m3;

    cout << "Enter first matrix:\n";
    m1.getData();

    cout << "Enter second matrix:\n";
    m2.getData();

    m3 = m1 + m2;

    cout << "\nAddition of matrices:\n";
    m3.display();

    cout << "Integer Addition: " << add(10, 20) << endl;
    cout << "Float Addition: " << add(2.5f, 3.5f) << endl;

    return 0;
}   