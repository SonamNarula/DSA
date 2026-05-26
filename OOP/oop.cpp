#include <iostream>
#include <string>
using namespace std;

class Teacher {
    // properties/attributes
   public:
    string name;
    string dept;
    string subject;
    double salary;

    // methods / member functions
    void changeDept(string newDept) { dept = newDept; }
};

int main() {
    // object
    Teacher t1;
    t1.name = "sonam";
    t1.subject = "C++";
    t1.dept = "CSE";
    t1.salary = 20000;

    cout << t1.name;
}