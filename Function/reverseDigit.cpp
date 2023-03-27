#include <iostream>
#include <vector>

using namespace std;

vector<int> reverseDigit(int);
void displayResult(vector<int>);

int main()
{
    long long number;
    cout << "Input a number: ";
    cin >> number;

    vector<int> revNumber = reverseDigit(number);

    displayResult(revNumber);
    return 0;
}

/**
 * This function will reverse the number and returns
 * in vector form.
 *
 * @param num holds the number from the user.
 *
 * @return the reversed number in vector form.
 */
vector<int> reverseDigit(int num)
{
    vector<int> reverseNum;
    int answer;
    if (num < 0)
    {
        num = num * (-1);
        cout << "-";
    }
    if (num == 0)
    {
        cout << 0;
    }

    while (num % 10 == 0)
        num = num / 10;

    while (num != 0)
    {
        answer = num % 10;
        num = num / 10;

        reverseNum.push_back(answer);
    }
    return reverseNum;
}

/**
 * This function will display the result.
 *
 * @param revNum holds the reversed number.
 */
void displayResult(vector<int> revNum)
{
    for (int index = 0; index < revNum.size(); index++)
        cout << revNum[index];
}