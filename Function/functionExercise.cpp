#include <iostream>

using namespace std;

int acceptNumber();
int findSum(int x, int y);
int findSum(int x, int y, int z);

int main()
{
    char ch;

    do
    {int amount;
    cout << "How many numbers will you add: ";
    cin >> amount;
    
    while (amount != 2 && amount != 3)
    {
        cout << "ERROR!!\n";
        cout << "The number you entered MUST be either 2 or 3\n";
        cout << "Enter the number: ";
        cin >> amount;
    }

    int num1, num2, num3;
    if (amount == 2)
    {
        num1 = acceptNumber();
        num2 = acceptNumber();

        int sum;
        sum = findSum(num1, num2);
        cout << "The sum is " << sum << endl;
    }
    else
    {
        num1 = acceptNumber();
        num2 = acceptNumber();
        num3 = acceptNumber();

        int sum;
        sum = findSum(num1, num2, num3);
        cout << "The sum is " << sum << endl;
    }

    cout << "Do you want to continue (Y/n): ";
    cin >> ch;
    } while (ch != 'n' && ch != 'N');
}

/**
 * This function will accept the numbers.
*/
int acceptNumber()
{
    int num;
    cout << "Enter Number: ";
    cin >> num;

    return num;
}

int findSum(int x, int y)
{
    return (x + y);
}

int findSum(int x, int y, int z)
{
    return (x + y + z);
}