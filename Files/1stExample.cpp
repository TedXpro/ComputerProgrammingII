#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream f1("example.txt");
    if (f1.is_open())
    {
        f1 << "This is a line.\n";
        f1 << "This is another line.\n";
        f1.close();
    }
    return 0;
}