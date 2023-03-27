#include <iostream>

using namespace std;

struct Car
{
    string brand;
    string model;
    int year;
};

int main()
{
    Car myCar1;
    myCar1.brand = "Mercedes";
    myCar1.model = "EQ";
    myCar1.year = 2022;

    Car myCar2;
    myCar2.brand = "Tesla";
    myCar2.model = "Model X";
    myCar2.year = 2020;

    cout << "Car 1:\n";
    cout << "Name: " << myCar1.brand << endl;
    cout << "Model: " << myCar1.model << endl;
    cout << "Year: " << myCar1.year << endl;

    cout << "Car 2:\n";
    cout << "Name: " << myCar2.brand << endl;
    cout << "Model: " << myCar2.model << endl;
    cout << "Year: " << myCar2.year << endl;
}
