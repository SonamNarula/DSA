// Given a Number N corresponding to a person's age (in days). Print his age in years, months and days, followed by its respective message "years", "months", "days".

// Note: consider the whole year has 365 days and 30 days per month.

// Input
// Only one line containing a number N (0 ≤ N ≤ 106).

// Output
// Print the output, like the following examples.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int years = N / 365;
    N = N % 365;

    int months = N / 30;
    int days = N % 30;

    cout << years << " years" << endl;
    cout << months << " months" << endl;
    cout << days << " days" << endl;

    return 0;
}
