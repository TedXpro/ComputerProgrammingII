/*This program will accept as many numbers the
user enters and finds the sum of the odd and
even numbers entered.*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> acceptNumbers(); 
vector<int> separateEvenOrOdd(vector<int>, char);
int findSum(vector<int>);
void displayResult(vector<int>, vector<int>, vector<int>, int, int);

int main()
{
    vector<int> numbers, even, odd;
    numbers = acceptNumbers();  // holds the numbers returned from the accept function.

    even = separateEvenOrOdd(numbers, 'E');
    odd = separateEvenOrOdd(numbers, 'O');

    int sumEven, sumOdd;
    sumEven = findSum(even);
    sumOdd = findSum(odd);

    displayResult(numbers, even, odd, sumEven, sumOdd);
}

/**
 * This function will accpet numbers from the user and
 * returns the numbers in vector form.
 *
 * @return the numbers in vector form.
 */
vector<int> acceptNumbers()
{
    vector<int> nums;
    while (true)
    {
        int n;
        cout << "Enter -1 to stop.\n";
        cout << "Enter number: ";
        cin >> n;
        if (n == -1)
            break;
        else
            nums.push_back(n);
    }
    return nums;
}

/**
 * This function will separate even numbers.
 *
 * @param nums holds the number entered by the user.
 *
 * @return the vector that holds even numbers.
 */
vector<int> separateEvenOrOdd(vector<int> nums, char ch)
{
    vector<int> num;
    if (ch == 'E')
    {
        for (int index = 0; index < nums.size(); index++)
        {
            if (nums[index] % 2 == 0)
                num.push_back(nums[index]);
        }
        return num;
    }
    else if(ch == 'O')
    {
        for (int index = 0; index < nums.size(); index++)
        {
            if (nums[index] % 2 != 0)
                num.push_back(nums[index]);
        }
        return num;
    }
    return num;
}

/**
 * This function will find the total of the even or odd numbers.
 *
 * @param evenOdd holds the even or odd number.
 *
 * @return the total of the even or odd numbers.
 */
int findSum(vector<int> evenOdd)
{
    int total = 0;
    for (int index = 0; index < evenOdd.size(); index++)
        total += evenOdd[index];

    return total;
}

/**
 * This function will display the result.
 *
 * @param nums holds the numbers entered by the user.
 * @param even holds numbers that are even.
 * @param odd holds numbers that are odd.
 * @param sumE holds the sum of even numbers.
 * @param sumO holds the sum of odd numbers.
 */
void displayResult(vector<int> nums, vector<int> even, vector<int> odd, int sumE, int sumO)
{
    cout << "The numbers you entered are:\n";
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    cout << "The even number are:\n";
    for (int i = 0; i < even.size(); i++)
        cout << even[i] << " ";
    cout << endl;
    cout << "The sum of the above even numbers is: " << sumE << endl;

    cout << "The odd number are:\n";
    for (int i = 0; i < odd.size(); i++)
        cout << odd[i] << " ";
    cout << endl;
    cout << "The sum of the above odd numbers is: " << sumO << endl;
}