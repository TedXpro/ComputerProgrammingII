/*      Name                ID
1. Newal Yeman          UGR/9108/14
2. Yigerem Bisrat       UGR/5026/14
3. Yodahe Gossa         UGR/9595/14
4. Yoak Moges           UGR/3567/14
5. Yohannes Belay       UGR/4223/14
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int R = 15; // The maximum row size of the two matrices, can be specified
const int C = 15; // The maximum column size of the two matrices, can be specified

int rowSize();
int columnSize();
void matRead(double[][C], int, int);
void matAdder(double matA[][C], double matB[][C], int, int);
void matSubtracter(double matA[][C], double matB[][C], int, int);
void matMultiplier(double matA[][C], double matB[][C], int, int, int);

int main()
{
    int repeat;
    char choice;
    double A[R][C];
    double B[R][C];

    do
    {
        system("cls");
        cout << "For the first matrix" << endl;
        int rowA = rowSize();
        int columnA = columnSize();

        matRead(A, rowA, columnA);
        system("cls");
        cout << "For the second matrix" << endl;
        int rowB = rowSize();
        int columnB = columnSize();

        matRead(B, rowB, columnB);

        if (rowA == rowB && columnA == columnB)
        {
            system("cls");
            matAdder(A, B, rowA, columnA);
            matSubtracter(A, B, rowA, columnA);
        }
        else
        {
            system("cls");
            cout << "\nAddition and subtraction are invalid for the two matrices since they have unequal dimension.";
        }
        if (columnA == rowB)
        {
            cout << endl;
            matMultiplier(A, B, rowA, columnA, columnB);
        }
        else
        {
            cout << "\nMultiplication is invalid since the number of columns of the first matrix is not ";
            cout << "equal to the number of rows of the second matrix.";
        }
        cout << "\nPress 0 to exit; otherwise press any key.";
        cin >> repeat;
    } while (repeat != 0);

    return 0;
}

int rowSize()
{
    int row;
    cout << "Enter the dimension of the matrix";
    do
    {
        cout << "\nEnter the number of rows: ";
        cin >> row;
        if (row < 1)
            cout << "Please enter a valid row size";
    } while (row < 1);
    return row;
}
int columnSize()
{
    int column;
    do
    {
        cout << "\nEnter the number of columns: ";
        cin >> column;
        if (column < 1)
            cout << "Please enter a valid column size";
    } while (column < 1);
    return column;
}
void matRead(double X[][15], int row, int column)
{
    system("cls");
    cout << "Enter the elements now." << endl;
    for (int i = 0; i < row; i++)
    {
        cout << "For row " << i + 1 << endl;
        for (int j = 0; j < column; j++)
        {
            cout << "Enter element " << j + 1 << ": ";
            cin >> X[i][j];
        }
    }
}

void matAdder(double matA[][C], double matB[][C], int row, int column)
{
    double result;
    cout << "\nHere is the sum of the two matrices" << endl;
    for (int m = 0; m < row; m++)
    {
        for (int n = 0; n < column; n++)
        {
            result = matA[m][n] + matB[m][n];
            cout << left << setw(6) << result;
        }
        cout << endl;
    }
}
void matSubtracter(double matA[][C], double matB[][C], int row, int column)
{
    double result;

    cout << "\nHere is the difference A-B: " << endl;
    for (int m = 0; m < row; m++)
    {
        for (int n = 0; n < column; n++)
        {
            result = matA[m][n] - matB[m][n];
            cout << left << setw(6) << result;
        }
        cout << endl;
    }
}
void matMultiplier(double matA[][C], double matB[][C], int rowA, int columnA, int columnB)
{
    double result = 0;
    cout << "\nHere is the multiplication A*B " << endl;
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < columnB; j++)
        {
            for (int k = 0; k < columnA; k++)
            {
                result += matA[i][k] * matB[k][j];
            }

            cout << left << setw(6) << result;
            result = 0;
        }
        cout << endl;
    }
}
