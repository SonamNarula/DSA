#include <iostream>
using namespace std;
 
int main() {
    int wt;
    cin >> wt;
 
    if (wt > 2 && wt % 2 == 0)
        cout << "YES";
    else
        cout << "NO";
 
    return 0;
}