#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // int num1, num2, num3, num4;
    // cout << "Enter num1: ";
    // cin >> num1;
    // cout << "Enter num 2: ";
    // cin >> num2;
    // cout << "Enter num 3: ";
    // cin >> num3;
    // cout << "Enter num 4: ";
    // cin >> num4;

    // ofstream outputFile;
    // outputFile.open("Demofile.txt");

    // outputFile << num1 << endl;
    // outputFile << num2 << endl;
    // outputFile << num3 << endl;
    // outputFile << num4 << endl;

    // outputFile.close();

    ifstream inputFile;
    inputFile.open("Demo.txt");
    int num, sum = 0;

    if (inputFile)
    {
        cout << "Created the file\n";
    }
    else{
        cout << "Didnt create the file\n";
    }

    while(inputFile >> num)
    {
        cout << num << endl;
        sum += num;
    }
    cout << sum << endl;
    inputFile.close();
}