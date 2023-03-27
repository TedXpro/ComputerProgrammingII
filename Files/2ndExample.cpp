#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    char buffer[256];

    ifstream f("example.txt");
    if (!f.is_open())
    {
        cout << "Error opening file";
        exit(1);
    }
    while (!f.eof())
    {
        f.getline(buffer, 256);
        cout << buffer << endl;
        // break;
    }
    return 0;
    
}