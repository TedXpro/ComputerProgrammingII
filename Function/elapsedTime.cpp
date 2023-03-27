/*This program will accept time in seconds and displays 
the time in hours:minutes:seconds.*/
#include <iostream>

using namespace std;

int main()
{
    int hrs = 3600, mins = 60;
    int second;
    cout << "Enter the time in second: ";
    cin >> second;

    int hour, minute, remainder;

    hour = second / hrs;
    remainder = second % hrs;

    minute = remainder / mins;
    remainder = remainder % mins;

    second = remainder;

    cout << "The time is: " << hour << ":" << minute << ":" << second << endl;
}