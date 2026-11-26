#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> marks = {75, 90, 60, 85, 50};

    
    sort(marks.begin(), marks.end());

    cout << "Sorted Marks: ";

    for (int m : marks)
        cout << m << " ";

    cout << endl;

    
    auto it = find_if(marks.begin(), marks.end(),
                      [](int m) { return m > 80; });

    if (it != marks.end())
        cout << "First mark above 80: " << *it << endl;

    
    transform(marks.begin(), marks.end(),
              marks.begin(),
              [](int m) { return m + 5; });

    cout << "Updated Marks: ";

    for (int m : marks)
        cout << m << " ";

    cout << endl;

    
    map<string, int> students;
    students["Rahul"] = 85;
    students["Amit"] = 90;

    cout << "\nStudent Records:\n";

    for (auto p : students)
        cout << p.first << ": " << p.second << endl;

    
    unordered_map<string, int> grades;
    grades["Rahul"] = 85;
    grades["Amit"] = 90;

    cout << "\nUnordered Map Size: "
         << grades.size() << endl;

    return 0;
}