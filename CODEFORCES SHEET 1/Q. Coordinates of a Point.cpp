// Given two numbers X, Y which donate coordinates of a point in 2D plan. Determine in which quarter does it belong.

// Note:

// Print Q1, Q2, Q3, Q4 according to the quarter in which the point belongs to.
// Print "Origem" If the point is at the origin.
// Print "Eixo X" If the point is over X axis.
// Print "Eixo Y" if the point is over Y axis.

// Input
// Only one line containing two numbers X, Y ( - 1000 ≤ X, Y ≤ 1000).

// Output
// Print the answer to problem above.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    double X, Y;
    cin >> X >> Y;

    if(X == 0 && Y == 0)
        cout << "Origem";
    else if(Y == 0)
        cout << "Eixo X";
    else if(X == 0)
        cout << "Eixo Y";
    else if(X > 0 && Y > 0)
        cout << "Q1";
    else if(X < 0 && Y > 0)
        cout << "Q2";
    else if(X < 0 && Y < 0)
        cout << "Q3";
    else
        cout << "Q4";

    return 0;
}
