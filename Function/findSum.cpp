#include <iostream>

using namespace std;

void acceptNumbers(int[], int);  // accepts the elements from the user.

int main()
{
    int size; // holds the size of the array.
    cout << "Enter the size of the array: ";
    cin >> size;

    int numbers[size];   // holds the numbers entered by the user.   EMPTY ARRAY
    acceptNumbers(numbers, size);   // numbers passed by position, size passed by value
    // from this line forward numbers holds the elements entered by the user.
}

void acceptNumbers(int nums[], int n)
{
    for (int i = 0; i < n; i++)  // n holds the size of the array.
    {
        cout << "Enter element #" << (i + 1) << ": ";
        cin >> nums[i];
    }
}
