#include <iostream>

using namespace std;

enum Days
{
    MONDAY = 3,   // MONDAY = 0
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

int main()
{
    for (int i = MONDAY; i <= FRIDAY; i++)
        {
            cout << i << endl;
            cout << "HELLOWORLD!" << endl;
        }
}