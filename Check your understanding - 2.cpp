// Given someone’s age, tell whether they are a child, adult,
// or a senior citizen.
// 0-17 : Child
// 18-64 : Adult
// 65+ : Senior Citizen

#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter age : ";
    cin >> age;

    if (age >= 0 && age <= 17) {
        cout << "Child";
    } else if (age >= 18 && age <= 64) {
        cout << "Adult";
    }

    else {
        cout << "Senior Citizen";
    }

    // 2. Take input of 3 numbers x, y, z and output the maximum
    // using if statements

    int x, y, z;
    cin >> x >> y >> z;

    if (x > y && x > z) {
        cout << "x is highest";
    }

    else if (y > x && y > z) {
        cout << "y is highest";
    }

    else
        cout << "z is highest";
}