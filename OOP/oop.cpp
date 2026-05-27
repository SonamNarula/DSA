#include <iostream>
#include <string>
using namespace std;

class Teacher {
    // properties/attributes

   private:
    double salary;

   public:
    string name;
    string dept;
    string subject;

    // methods / member functions
    void changeDept(string newDept) { dept = newDept; }
    // setter
    void setSalary(double s) { salary = s; }

    // getter
    double getSalary() { return salary; }
};

int main() {
    // object
    Teacher t1;
    t1.name = "sonam";
    t1.subject = "C++";
    t1.dept = "CSE";
    t1.setSalary(20000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;

    return 0;
}
