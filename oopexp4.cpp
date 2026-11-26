#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;

    void getPerson()
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter age: ";
        cin >> age;
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person
{
public:
    int rollNo;

    void getStudent()
    {
        cout << "Enter roll number: ";
        cin >> rollNo;
    }

    void displayStudent()
    {
        cout << "Roll Number: " << rollNo << endl;
    }
};

class GraduateStudent : public Student
{
public:
    string researchTopic;

    void getGraduate()
    {
        cout << "Enter research topic: ";
        cin >> researchTopic;
    }

    void displayGraduate()
    {
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main()
{
    GraduateStudent g;

    g.getPerson();
    g.getStudent();
    g.getGraduate();

    cout << "\n--- Graduate Student Details ---" << endl;

    g.displayPerson();
    g.displayStudent();
    g.displayGraduate();

    return 0;
}   