#include <iostream>

using namespace std;

void myFunction(int num[])
{
    for (int i = 0; i < 5; i ++)
        cout << num[i] << " ";
}

int main()
{
    int num[] = {10, 20, 30, 40, 50};
    myFunction(num);
}