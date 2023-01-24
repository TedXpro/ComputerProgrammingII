#include <iostream>

using namespace std;

int acceptNumber();
int findSum(int);
int findFactorial(int);
int findFibinachi(int);

int main()
{
    int number;
    number = acceptNumber();
    while (number < 0)
    {
        cout << "Enter a number greater or equall to 0:\n";
        number = acceptNumber();
    }

    int summation = findSum(number);
    cout << "The sum of the numbers till zero is: " << summation << endl;

    int factorial = findFactorial(number);
    cout << "The factorial of the number " << number << " is " << factorial << endl;

    int fibinachi = findFibinachi(number);
    cout << "The " << number << "th fibinachi number is " << fibinachi << endl;
}

/**
 * This function will accept the number from the user.
 * 
 * @return the number the user enters.
*/
int acceptNumber()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    return num;
}

/**
 * This function will find the sum of the number till zero.
 * 
 * @param num holds the number entered by the user.
 * 
 * @return the sum of the number till 0.
*/
int findSum(int num)
{
    if (num == 0)
        return 0;
    else if ( num == 1)
        return 1;
    return num + findSum(num - 1);
}

/**
 * This function will find the factorial of the number.
 * 
 * @param num holds the number given by the user.
 * 
 * @return the factorial of the number.
*/
int findFactorial(int num)  // num = 5
{
    if (num < 0)
        return 0;
    else if (num == 0 || num == 1)
        return 1;
    return num * findFactorial(num - 1);
}

/**
 * This function will find the fibinachi number.
 * 
 * @param num holds the number entered by the user.
 * 
 * @return the num'th fibinachi number.
*/
int findFibinachi(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    return (findFibinachi(num - 1) + findFibinachi(num - 2));

    // if (num == 0)
    //     return 0;
    // if (num == 1)
    //     return 1;
    // int i = 1, j = 0;
    // int val;
    // for (int index = 2; index <= num; index++)
    // {
    //     val = i + j;
    //     j = i;    
    //     i = val;
    // }
    // return val;
}