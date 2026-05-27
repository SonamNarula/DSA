#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
    // man made constructor
    Teacher() { dept = "Computer Science"; }
    // properties/attributes

private:
    double salary = 0;

public:
    string name;
    string dept;
    string subject;

    // methods / member functions
    void changeDept(string newDept) { dept = newDept; }
    // setter
    void setSalary(double s) { salary = s; }

    // getter
    double getSalary() const { return salary; }
};

class Account {
private:
    // data hiding
    double balance = 0;
    string password;

public:
    string accountId;
    string username;

    void setBalance(double b) { balance = b; }
    double getBalance() const { return balance; }
};

int main() {
    // object
    Teacher t1;  // constructor call
    t1.name = "sonam";
    t1.subject = "C++";
    // t1.dept = "CSE";
    t1.setSalary(20000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;
    cout << t1.dept;

    return 0;
}
