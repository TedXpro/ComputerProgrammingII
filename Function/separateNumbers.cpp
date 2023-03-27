/*This program will accept number from the user
and outputs the numbers separated and the sum.*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int number, num;
    vector<int> vecNumber;

    cout << "Enter the number: ";
    cin >> number;

    int sum = 0;

    while (number != 0)
    {
        num = number % 10;
        vecNumber.push_back(num);
        sum += num;
        number = number / 10;
    }
    for (int i = vecNumber.size(); i > 0; i--)
        cout << vecNumber[i - 1] << " ";

    cout << endl << sum << endl;
}
