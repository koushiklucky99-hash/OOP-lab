#include <iostream>
using namespace std;

int main()
{
    int age;
    float marks;
    char grade;
    const float PI = 3.14;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter marks: ";
    cin >> marks;

    cout << "Enter grade: ";
    cin >> grade;

    cout << "\n--- Student Details ---" << endl;
    cout << "Age: " << age << endl;
    cout << "Marks: " << marks << endl;
    cout << "Grade: " << grade << endl;
    cout << "PI: " << PI << endl;

    cout << "Addition: " << age + 10 << endl;
    cout << "Multiplication: " << age * 2 << endl;

    return 0;
}