#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout("test.txt");

    int x;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter your data\n";
        cin >> x;
        fout << x << endl;
    }

    // fout<<"Test";
    fout.close();
    ifstream file("test.txt");

    if (!file)
    { // operator! is used here
        cout << "File opening failed\n";
        return 0;
    }
    for (int n; file >> n;)
    {
        cout << n << " ";
    }
    cout << "\n";

    if (file.bad())
        cout << "I/O error while reading\n";
    else if (file.eof())
        cout << "End of file reached successfully\n";
    else if (file.fail())
        cout << "Non-integer data encountered\n";
    file.close();
}
