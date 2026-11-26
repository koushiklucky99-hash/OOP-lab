
#include <iostream>
#include <string>
using namespace std;

class Course
{
private:
    int courseID;
    string courseName;
    int seats;

public:
    Course(int id, string name, int s)
    {
        courseID = id;
        courseName = name;
        seats = s;
    }

    int getID()
    {
        return courseID;
    }

    string getName()
    {
        return courseName;
    }

    int getSeats()
    {
        return seats;
    }

    void registerStudent()
    {
        if(seats > 0)
        {
            seats--;
            cout << "Course registered successfully!\n";
        }
        else
        {
            cout << "No seats available!\n";
        }
    }

    void displayCourse()
    {
        cout << courseID << "\t"
             << courseName << "\t"
             << seats << endl;
    }
};

class Student
{
private:
    int studentID;
    string studentName;
    int registeredCourses[5];
    int count;

public:
    Student(int id, string name)
    {
        studentID = id;
        studentName = name;
        count = 0;
    }

    void registerCourse(Course courses[], int n)
    {
        int id;
        cout << "Enter Course ID: ";
        cin >> id;

        for(int i = 0; i < n; i++)
        {
            if(courses[i].getID() == id)
            {
                for(int j = 0; j < count; j++)
                {
                    if(registeredCourses[j] == id)
                    {
                        cout << "Already registered!\n";
                        return;
                    }
                }

                if(count < 5 && courses[i].getSeats() > 0)
                {
                    courses[i].registerStudent();
                    registeredCourses[count] = id;
                    count++;
                }
                else if(count >= 5)
                {
                    cout << "Maximum course limit reached!\n";
                }
                return;
            }
        }

        cout << "Invalid Course ID!\n";
    }

    void displayRegisteredCourses(Course courses[], int n)
    {
        cout << "\nStudent Name: " << studentName << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Registered Courses:\n";

        if(count == 0)
        {
            cout << "No courses registered.\n";
            return;
        }

        for(int i = 0; i < count; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(registeredCourses[i] == courses[j].getID())
                {
                    cout << courses[j].getID()
                         << " - "
                         << courses[j].getName() << endl;
                }
            }
        }
    }
};

int main()
{
    Course courses[5] = {
        Course(101, "C++ Programming", 30),
        Course(102, "Data Structures", 25),
        Course(103, "Database", 20),
        Course(104, "Computer Networks", 15),
        Course(105, "Cyber Security", 10)
    };

    int id;
    string name;
    int choice;

    cout << "Enter Student ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, name);

    Student s(id, name);

    do
    {
        cout << "\n===== COLLEGE COURSE REGISTRATION =====\n";
        cout << "1. Display Available Courses\n";
        cout << "2. Register Course\n";
        cout << "3. View Registered Courses\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nID\tCourse Name\t\tSeats\n";
                for(int i = 0; i < 5; i++)
                {
                    courses[i].displayCourse();
                }
                break;

            case 2:
                s.registerCourse(courses, 5);
                break;

            case 3:
                s.displayRegisteredCourses(courses, 5);
                break;

            case 4:
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}
