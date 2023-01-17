#include <iostream>
using namespace std;

struct
{
    int myNum;
    string myString;
} myStructure;

int main()
{
    myStructure.myNum = 2;
    myStructure.myString = "class";
    cout << myStructure.myNum << endl;
    cout << myStructure.myString << endl;
}