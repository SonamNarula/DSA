#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    string ans = "";
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            ans += c;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
