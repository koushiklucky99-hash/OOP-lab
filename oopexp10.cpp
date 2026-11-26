#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file;
    int roll, marks;
    string name;

    
    file.open("students.csv",
              ios::out | ios::trunc);

    file << "Roll,Name,Marks\n";
    file << "1,Rahul,85\n";
    file << "2,Amit,90\n";
    file << "3,Neha,95\n";

    cout << "Data written successfully!" << endl;

    cout << "Write position: " << file.tellp() << endl;

    file.close();

    
    file.open("students.csv", ios::in);

    cout << "\nStudent Records:\n";

    string line;
    getline(file, line); 

    while (getline(file, line))
    {
        cout << line << endl;
    }

    
    file.clear();
    file.seekg(0, ios::beg);

    cout << "\nRead position: " << file.tellg() << endl;

    file.close();

    
    file.open("students.csv", ios::in | ios::out);

    file.seekp(0, ios::end);

    cout << "End position: " << file.tellp() << endl;

    file.close();

    return 0;
}