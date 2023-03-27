#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myFile;
    ifstream file;
    char ch[30];
    char text;
    cout << "Enter some Text here: " << endl;
    cin.getline(ch, 30);

    myFile.open("InfoBrother.txt", ios::out);
    if (myFile)
    {
        myFile << ch;
        cout << "Data store Successfully: \n"
             << endl;
    }
    else
        cout << " Error while opening file: " << endl;
    myFile.close();

    file.open("InfoBrother.txt", ios::in);
    if (file)
    {
        file.seekg(-11, ios::end);
        cout << "\n The last 11 bytes are: ";
        while (!file.eof())
        {
            file.get(text);
            cout << text;
        }
    }
    else
        cout << " Error while Opening File: " << endl;
    file.close();
    int pos;
    cout << "Enter the position: ";
    cin >> pos;
    char word;
    cout >> "Enter the string: ";
    cin >> word;

    myFile.open("InfoBrother.txt", ios::out);
    myFile.seekp(pos, ios::beg)
        myFile.put(word);
    myFile.close();
    return 0;
}
