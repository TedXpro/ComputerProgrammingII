#include <iostream>

using namespace std;

union RecordType
{
    /* data */
    char ch;
    int i;
    float f;
    double d;
    int *intPtr;
};

int main()
{
    RecordType record;
    record.i = 12;
    record.f = 453.34;
    // record.ch = 'K';

    cout << record.f << endl;
    cout << record.i << endl;
    // cout << record.ch << endl;
}
