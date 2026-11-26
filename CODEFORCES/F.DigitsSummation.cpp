#include <iostream>
using namespace std;

int main() {
    // Changed 'int' to 'long long' to handle numbers up to 10^18
    long long a, b; 
    cin >> a >> b;

    cout << ((a % 10) + (b % 10));
    return 0;
}