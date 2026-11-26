// Given a letter X. If the letter is lowercase print the letter after converting it from lowercase letter to uppercase letter. Otherwise print the letter after converting it from uppercase letter to lowercase letter

// Note : difference between 'a' and 'A' in ASCII is 32 .

// Input
// Only one line containing a character X which will be a capital or small letter.

// Output
// Print the answer to this problem.

#include<bits/stdc++.h>
using namespace std;

int main(){
    char X;
    cin >> X;

    if (X >= 'A' && X <= 'Z')
    cout << (char)(X+32);

    else
    cout << (char)(X+32);
}