#include <iostream>
#include <string>
using namespace std;

class Teacher {
   public:
    // man made constructor
    // non parameterised
    Teacher() { dept = "Computer Science"; }
    // properties/attributes

    // parameterised constructor
    Teacher(string n, string s, string d, double sal) {
        name = n;
        subject = s;
        dept = d;
        salary = sal;
    }

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

    void getInfo(){
        cout << "Name : " << name << endl;
        cout <<"Subject : " << subject << endl;
    }
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

    // void getInfo() const {
    //     cout << "Account ID : " << accountId << endl;
    //     cout << "Username : " << username << endl;
    // }
};

int main() {
    // object
    Teacher t1("Sonam", "c++", "cse", 20000);  // constructor call
    // t1.getInfo();
    Teacher t2(t1);
    t2.getInfo();
    // t1.name = "sonam";
    // t1.subject = "C++";
    // // t1.dept = "CSE";
    // t1.setSalary(20000);

    // cout << t1.name << endl;
    // cout << t1.getSalary() << endl;
    // cout << t1.dept << endl;

    return 0;
}
