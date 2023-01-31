#include <iostream>

using namespace std;

struct Distance
{
    int feet;
    float inch;
};

int main()
{
    Distance *ptr, d;

    ptr = &d;

    cout << "Enter the feet: ";
    cin >> (*ptr).feet;
    cout << "Enter the inch: ";
    cin >> ptr->inch;

    cout << ptr->feet << " " << (*ptr).inch << endl;
    // cout << d.feet << " " << d.inch << endl;
}